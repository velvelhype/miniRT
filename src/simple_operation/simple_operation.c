#include "simple_operation.h"
#include "math.h"

double	square(double val)
{
	return (val * val);
}

double	quadratic_equation(double A, double B, double C, double D)
{
	double	t;

	t = 0;
	if (D == 0)
		t = -B  / (2 * A);
	if (D > 0)
	{
		double t1 = (-B + sqrt(D)) / (2 * A);
		double t2 = (-B - sqrt(D)) / (2 * A);
		if (t1 > 0)
			t = t1;
		if (t2 > 0 && t2 < t)
			t = t2;
	}
	return (t);
}

double	clamp(double val, double min, double max)
{
	if (val < min)
		val = min;
	if (val > max)
		val = max;
	return (val);
}