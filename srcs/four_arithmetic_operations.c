#include "../includes/fixed_point.h"

t_fixed	add_fixed(t_fixed val1, void *val2, t_arg_type type)
{
	if (type == FIXED)
		return (val1 + *(t_fixed *)val2);
	else if (type == INT)
		return (val1 + (*(int *)val2 * FLOATING_POINT));
	else
		return (val1 + double_to_fixed(*(double *)val2));
}

t_fixed	sub_fixed(t_fixed val1, void *val2, t_arg_type type)
{
	if (type == FIXED)
		return (val1 - *(t_fixed *)val2);
	else if (type == INT)
		return (val1 - (*(int *)val2 * FLOATING_POINT));
	else
		return (val1 - double_to_fixed(*(double *)val2));
}

t_fixed	mul_fixed(t_fixed val1, void *val2, t_arg_type type)
{
	if (type == FIXED)
		return (((val1 * *(t_fixed *)val2) / FLOATING_POINT));
	else if (type == INT)
		return (val1 * *(int *)val2);
	else
		return (((val1 * double_to_fixed(*(double *)val2)) / FLOATING_POINT));
}

t_fixed	div_fixed(t_fixed val1, void *val2, t_arg_type type)
{
	if (type == FIXED)
		return ((val1 * FLOATING_POINT) / *(t_fixed *)val2);
	else if (type == INT)
		return (val1 / *(int *)val2);
	else
		return ((val1 * FLOATING_POINT) / double_to_fixed(*(double *)val2));
}
