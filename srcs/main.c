#include "../includes/fixed_point.h"

#include <stdio.h>
#include <string.h>

#define FMT "double : %f\nfixed  : %f\n\n"

enum
{
	VALUE1 = 1,
	VALUE2,
	OPERATION,
};

int main(int argc, char **argv)
{
	if (argc < 3)
		exit(1);

	double	double1 = atof(argv[VALUE1]);
	double	double2 = atof(argv[VALUE2]);

	t_fixed	fixed1 = double_to_fixed(double1);
	t_fixed	fixed2 = double_to_fixed(double2);

	printf("[%s %s %s]\n", argv[VALUE1], argv[VALUE2], argv[OPERATION]);

	if (!strcmp(argv[OPERATION], "add"))
		printf(FMT, (double1 + double2), fixed_to_double(_add(fixed1, fixed2)));
	else if (!strcmp(argv[OPERATION], "sub"))
		printf(FMT, (double1 - double2), fixed_to_double(_sub(fixed1, fixed2)));
	else if (!strcmp(argv[OPERATION], "mul"))
		printf(FMT, (double1 * double2), fixed_to_double(_mul(fixed1, fixed2)));
	else if (!strcmp(argv[OPERATION], "div"))
		printf(FMT, (double1 / double2), fixed_to_double(_div(fixed1, fixed2)));
	return (0);
}
