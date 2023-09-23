#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <math.h>
#include <unistd.h>
#include <stdlib.h>

typedef int t_fixed;

enum e_floating_point
{
	SHIFT_NUMBER = 8,
	FLOATING_POINT = (1U << SHIFT_NUMBER),
};

typedef enum e_arg_type
{
	FIXED,
	INT,
	DOUBLE,
}	t_arg_type;

// cast
t_fixed	double_to_fixed(double number);
double	fixed_to_double(t_fixed fixed);

// four arithmetic operatoins
t_fixed	add_fixed(t_fixed val1, void *val2, t_arg_type type);
t_fixed	sub_fixed(t_fixed val1, void *val2, t_arg_type type);
t_fixed	mul_fixed(t_fixed val1, void *val2, t_arg_type type);
t_fixed	div_fixed(t_fixed val1, void *val2, t_arg_type type);

#endif
