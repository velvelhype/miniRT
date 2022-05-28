/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:33:53 by akito             #+#    #+#             */
/*   Updated: 2022/04/24 13:33:53 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cylinder	*init_cylinder(t_cylinder cylinder)
{
	t_cylinder	*res;

	res = (t_cylinder *)ft_calloc(sizeof(t_cylinder), 1);
	res->type = cylinder.type;
	res->coord = cylinder.coord;
	res->orient = cylinder.orient;
	res->diameter = cylinder.diameter;
	res->height = cylinder.height;
	res->color = cylinder.color;
	return (res);
}
