#include "../includes/fixed_point.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	if (argc < 3)
		exit(1);

	double	double1 = atof(argv[1]);
	double	double2 = atof(argv[2]);

	t_fixed	fixed1 = double_to_fixed(double1);
	t_fixed	fixed2 = double_to_fixed(double2);

	printf("[%s %s %s]\n", argv[1], argv[2], argv[3]);
	if (!strcmp(argv[3], "add"))
		printf("double : %f\nfixed  : %f\n\n", (double1 + double2), fixed_to_double(add_fixed(fixed1, fixed2)));
	else if (!strcmp(argv[3], "sub"))
		printf("double : %f\nfixed  : %f\n\n", (double1 - double2), fixed_to_double(sub_fixed(fixed1, fixed2)));
	else if (!strcmp(argv[3], "mul"))
		printf("double : %f\nfixed  : %f\n\n", (double1 * double2), fixed_to_double(mul_fixed(fixed1, fixed2)));
	else if (!strcmp(argv[3], "div"))
		printf("double : %f\nfixed  : %f\n\n", (double1 / double2), fixed_to_double(div_fixed(fixed1, fixed2)));
	return (0);
}
