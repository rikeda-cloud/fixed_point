#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <math.h>
#include <unistd.h>
#include <stdlib.h>

#ifdef	DOUBLE
typedef double t_fixed;
#elif	FLOAT
typedef float t_fixed;
#elif	LONG
typedef long t_fixed;
#elif	LLONG
typedef long long t_fixed;
#else
typedef int t_fixed;
#endif

enum e_floating_point
{
	SHIFT_NUMBER = 8,
	FLOATING_POINT = (1U << SHIFT_NUMBER),
};

// cast
t_fixed	double_to_fixed(double number);
double	fixed_to_double(t_fixed fixed);
t_fixed	int_to_fixed(int number);

// four arithmetic operatoins
t_fixed	_add(t_fixed val1, t_fixed val2);
t_fixed	_sub(t_fixed val1, t_fixed val2);
t_fixed	_mul(t_fixed val1, t_fixed val2);
t_fixed	_div(t_fixed val1, t_fixed val2);

#endif
