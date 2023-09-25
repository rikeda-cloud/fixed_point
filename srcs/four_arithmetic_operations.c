#include "../includes/fixed_point.h"

t_fixed	_add(t_fixed val1, t_fixed val2)
{
	return (val1 + val2);
}

t_fixed	_sub(t_fixed val1, t_fixed val2)
{
	return (val1 - val2);
}

t_fixed	_mul(t_fixed val1, t_fixed val2)
{
	#ifdef DOUBLE
	return (val1 * val2);
	#elif FLOAT
	return (val1 * val2);
	#else
	return ((val1 * val2) >> SHIFT_NUMBER);
	#endif
}

t_fixed	_div(t_fixed val1, t_fixed val2)
{
	#ifdef DOUBLE
	return (val1 / val2);
	#elif FLOAT
	return (val1 / val2);
	#else
	return ((val1 << SHIFT_NUMBER) / val2);
	#endif
}
