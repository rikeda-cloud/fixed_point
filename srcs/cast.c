#include "../includes/fixed_point.h"

t_fixed	double_to_fixed(double number)
{
	#ifdef DOUBLE
	return (number);
	#elif FLOAT
	return (number);
	#else
	return (roundf(number * FLOATING_POINT));
	#endif
}

t_fixed	int_to_fixed(int number)
{
	#ifdef DOUBLE
	return (number);
	#elif FLOAT
	return (number);
	#else
	return (number * FLOATING_POINT);
	#endif
}

double	fixed_to_double(t_fixed fixed)
{
	#ifdef DOUBLE
	return (fixed);
	#elif FLOAT
	return (fixed);
	#else
	return (fixed * (1.0 / FLOATING_POINT));
	#endif
}
