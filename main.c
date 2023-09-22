#include "includes/minirt.h"

static t_fixed	double_to_fixed_point(double number)
{
	t_fixed	fixed;

	fixed.point = FLOATING_POINT;
	fixed.value = (int)roundf(number * (1U << fixed.point));
	return (fixed);
}

static double	fixed_point_to_double(t_fixed fixed_point)
{
	double	number;

	number = (double)fixed_point.value / (1U << fixed_point.point);
	return (number);
}

t_fixed	add(t_fixed fixed1, t_fixed fixed2)
{
	t_fixed	result;

	result.point = fixed1.point;
	result.value = fixed1.value + fixed2.value;
	return (result);
}

t_fixed	sub(t_fixed fixed1, t_fixed fixed2)
{
	t_fixed	result;

	result.point = fixed1.point;
	result.value = fixed1.value - fixed2.value;
	return (result);
}

int	main(void)
{
	double	double_number1 = 1543.533234;
	double	double_number2 = 4.34444445234;

	t_fixed	fixed_number1;
	t_fixed	fixed_number2;
	t_fixed	result;

	fixed_number1 = double_to_fixed_point(double_number1);
	fixed_number2 = double_to_fixed_point(double_number2);
	/* result = add(fixed_number1, fixed_number2); */
	result = sub(fixed_number1, fixed_number2);

	printf("double_number1 + double_number2 = %f\n", double_number1 - double_number2);
	printf("fixed_number1 + fixed_number2 = %f\n", fixed_point_to_double(result));
	
	return (0);
}
