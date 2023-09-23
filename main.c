#include "fixed_point.h"

static t_fixed_point	double_to_fixed(double number)
{
	return (roundf(number * FLOATING_POINT));
}

static double	fixed_to_double(t_fixed_point fixed)
{
	return (fixed / FLOATING_POINT);
}

t_fixed_point	add(t_fixed_point value1, int value2)
{
	return (value1 + (value2 * FLOATING_POINT));
}

t_fixed_point	sub(t_fixed_point value1, int value2)
{
	return (value1 - (value2 * FLOATING_POINT));
}

int	main(void)
{
	double	double1 = 1543.3234;
	double	double2 = 4.345234;

	t_fixed_point	fixed1;
	t_fixed_point	fixed2;
	t_fixed_point	result;

	fixed1 = double_to_fixed(double1);
	fixed2 = double_to_fixed(double2);
	result = fixed1 + fixed2;
	/* result = add(fixed1, fixed2); */
	/* result = sub(fixed1, -20); */

	printf("double_number1 + double_number2 = %f\n", double1 + double2);
	printf("fixed_number1 + fixed_number2 = %f\n", fixed_to_double(result));
	
	return (0);
}
