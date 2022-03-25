#include "vector.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

float	len_vector(t_vector	*v1, t_vector *v2)
{
	float	len;

	len = pow(v1->x - v2->x, 2);
	len += pow(v1->y - v2->y, 2);
	len += pow(v1->z - v2->z, 2);
	return (sqrt(len));
}

void	init_vector(t_vector *vec, float arg_x, float arg_y, float arg_z)
{
	vec->x = arg_x;
	vec->y = arg_y;
	vec->z = arg_z;
}

float	squared_norm(const t_vector*v)
{
	return (pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2));
}

float	norm(const t_vector *v)
{
	return (sqrt(squared_norm(v)));
}

float	normalize(t_vector *v)
{
	float	vnorm;

	vnorm = norm(v);
	if (vnorm == 0)
		exit(2);
	v->x /= vnorm;
	v->y /= vnorm;
	v->z /= vnorm;
	return (vnorm);
}
