/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:33:53 by akito             #+#    #+#             */
/*   Updated: 2022/04/24 13:33:53 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_plane	*init_plane(t_plane plane)
{
	t_plane	*res;

	res = (t_plane *)ft_calloc(sizeof(t_plane), 1);
	res->type = plane.type;
	res->coord = plane.coord;
	res->orient = plane.orient;
	res->color = plane.color;
	return (res);
}
