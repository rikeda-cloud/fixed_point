#include "../includes/fixed_point.h"

#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#define LOOP_NUMBER 10000

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

static void	bench_mark(t_fixed fixed1, t_fixed fixed2)
{
	size_t			i = 0;
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	while (i++ < LOOP_NUMBER)
	{
		fixed1 = mul_fixed(fixed1, fixed2);
	}
	printf("diff time = %lldus\n", diff_time(&start_time));
	printf("value = %f\n", fixed_to_double(fixed1));
}

int main(void)
{
	double	double1 = 1.0;
	double	double2 = 1.001;

	t_fixed	fixed1 = double_to_fixed(double1);
	t_fixed	fixed2 = double_to_fixed(double2);

	bench_mark(fixed1, fixed2);
	return (0);
}
