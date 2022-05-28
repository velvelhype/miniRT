/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:39:25 by akito             #+#    #+#             */
/*   Updated: 2022/05/21 11:39:25 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_operation.h"
#include "math.h"

double	square(double val)
{
	return (val * val);
}

double	quadratic_equation(double A, double B, double C, double D)
{
	double	t;
	double	t1;
	double	t2;

	(void)C;
	t = 0;
	if (D == 0)
		t = -B / (2 * A);
	if (D > 0)
	{
		t1 = (-B + sqrt(D)) / (2 * A);
		t2 = (-B - sqrt(D)) / (2 * A);
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
