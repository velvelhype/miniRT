/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:32:50 by akito             #+#    #+#             */
/*   Updated: 2022/05/28 20:32:50 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>
#include "simple_operation.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"

double	len_vector(t_vector	*v1, t_vector *v2)
{
	double	len;

	len = square(v1->x - v2->x);
	len += square(v1->y - v2->y);
	len += square(v1->z - v2->z);
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
		custom_exit("invalid object setting");
	v->x /= vnorm;
	v->y /= vnorm;
	v->z /= vnorm;
	return (vnorm);
}
