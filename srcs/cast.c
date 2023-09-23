#include "../includes/fixed_point.h"

t_fixed	double_to_fixed(double number)
{
	return (roundf(number * FLOATING_POINT));
}

t_fixed	int_to_fixed(int number)
{
	return (number * FLOATING_POINT);
}

double	fixed_to_double(t_fixed fixed)
{
	return (fixed * (1.0 / FLOATING_POINT));
}
