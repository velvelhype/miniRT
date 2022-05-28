/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternary_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:39:25 by akito             #+#    #+#             */
/*   Updated: 2022/05/21 11:39:25 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
