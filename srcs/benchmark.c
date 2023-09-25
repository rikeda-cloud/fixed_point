#include "../includes/fixed_point.h"

#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#define LOOP_NUMBER 10000

enum
{
	VALUE1 = 1,
	VALUE2,
	OPERATION,
};

static long long int	diff_time(struct timeval *time)
{
	struct timeval	new_time;
	long long int	sec;
	long long int	usec;

	gettimeofday(&new_time, NULL);
	sec = (new_time.tv_sec - time->tv_sec) * 1000000;
	usec = (new_time.tv_usec - time->tv_usec);
	return (sec + usec);
}

static void	bench_mark(t_fixed fixed1, t_fixed fixed2, t_fixed (*f)(t_fixed, t_fixed))
{
	size_t			i = 0;
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	while (i++ < LOOP_NUMBER)
		fixed1 = f(fixed1, fixed2);
	printf("diff time = %lldus\nvalue = %f\n\n", diff_time(&start_time), fixed_to_double(fixed1));
}

int main(int argc, char **argv)
{
	if (argc < 3)
		exit(1);

	double	double1 = atof(argv[VALUE1]);
	double	double2 = atof(argv[VALUE2]);

	t_fixed	fixed1 = double_to_fixed(double1);
	t_fixed	fixed2 = double_to_fixed(double2);

	printf("[(%s %s= %s) * %d]\n", argv[VALUE1], argv[OPERATION], argv[VALUE2], LOOP_NUMBER);

	if (!strcmp(argv[OPERATION], "add"))
		bench_mark(fixed1, fixed2, _add);
	else if (!strcmp(argv[OPERATION], "sub"))
		bench_mark(fixed1, fixed2, _sub);
	else if (!strcmp(argv[OPERATION], "mul"))
		bench_mark(fixed1, fixed2, _mul);
	else if (!strcmp(argv[OPERATION], "div"))
		bench_mark(fixed1, fixed2, _div);

	return (0);
}
