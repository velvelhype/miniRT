#include "simple_operation.h"

float	max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

float	mod(float val)
{
	if (val < 0)
		return (-val);
	else
		return (val);
}
