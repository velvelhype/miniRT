/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_operation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:39:25 by akito             #+#    #+#             */
/*   Updated: 2022/05/21 11:39:25 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_OPERATION_H
# define SIMPLE_OPERATION_H

double	max(double a, double b);
double	min(double a, double b);
double	mod(double val);
double	square(double val);
double	quadratic_equation(double A, double B, double C, double D);
double	clamp(double val, double min, double max);
#endif