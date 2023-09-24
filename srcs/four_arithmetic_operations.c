#include "../includes/fixed_point.h"

t_fixed	add_fixed(t_fixed val1, t_fixed val2)
{
	return (val1 + val2);
}

t_fixed	sub_fixed(t_fixed val1, t_fixed val2)
{
	return (val1 - val2);
}

t_fixed	mul_fixed(t_fixed val1, t_fixed val2)
{
	#ifdef DOUBLE
	return (val1 * val2);
	#elif FLOAT
	return (val1 * val2);
	#else
	return ((val1 * val2) / FLOATING_POINT);
	#endif
}

t_fixed	div_fixed(t_fixed val1, t_fixed val2)
{
	#ifdef DOUBLE
	return (val1 / val2);
	#elif FLOAT
	return (val1 / val2);
	#else
	return ((val1 * FLOATING_POINT) / val2);
	#endif
}
