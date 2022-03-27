#include "vector.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

double	len_vector(t_vector	*v1, t_vector *v2)
{
	double	len;

	len = pow(v1->x - v2->x, 2);
	len += pow(v1->y - v2->y, 2);
	len += pow(v1->z - v2->z, 2);
	return (sqrt(len));
}

void	init_vector(t_vector *vec, double arg_x, double arg_y, double arg_z)
{
	vec->x = arg_x;
	vec->y = arg_y;
	vec->z = arg_z;
}

double	squared_norm(const t_vector*v)
{
	return (pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2));
}

double	norm(const t_vector *v)
{
	return (sqrt(squared_norm(v)));
}

double	normalize(t_vector *v)
{
	double	vnorm;

	vnorm = norm(v);
	if (vnorm == 0)
		exit(2);
	v->x /= vnorm;
	v->y /= vnorm;
	v->z /= vnorm;
	return (vnorm);
}
