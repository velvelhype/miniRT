#include "simple_operation.h"

double	max(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

double	min(double a, double b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

double	mod(double val)
{
	if (val < 0)
		return (-val);
	else
		return (val);
}
