#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <math.h>
#include <unistd.h>
#include <stdlib.h>

/* debug */
#include <stdio.h>
/* debug */

#define SHIFT_NUMBER 16

enum
{
	FLOATING_POINT = (1U << SHIFT_NUMBER),
};

typedef int t_fixed_point;

#endif
