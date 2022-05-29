/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:56:14 by akito             #+#    #+#             */
/*   Updated: 2022/05/29 17:05:10 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <math.h>
#include "render.h"

t_vector	make_shadow_ray(t_rt *rt_info, t_front_point *intersection)
{
	t_vector	shadow_ray;

	shadow_ray = sub_vecs(&rt_info->light.coord, &intersection->coord);
	normalize(&shadow_ray);
	return (shadow_ray);
}

bool	colide_s_ray_objs(t_list *objs, t_vector s, t_vector isp, double max)
{
	t_front_point	pt;
	t_obj			*obj;

	pt.length = 0;
	while (objs)
	{
		obj = objs->content;
		if (obj->type == SPHERE)
			pt = colide_cam_ray_and_sp(&s, &isp, objs->content);
		if (obj->type == PLANE)
			pt = colide_cam_ray_and_plane(&s, &isp, objs->content);
		if (obj->type == CYLINDER)
			pt = colide_ray_and_cyl(&s, &isp, objs->content);
		if (pt.length && pt.length < max)
			return (TRUE);
		objs = objs->next;
	}
	return (FALSE);
}

bool	is_in_shadow(t_rt *rt_info, t_front_point *intersection, t_list	*objs)
{
	t_vector	shadow_ray;
	t_vector	epsilon_shadow_ray;
	t_vector	isp;
	double		max_len;

	shadow_ray = make_shadow_ray(rt_info, intersection);
	epsilon_shadow_ray = mult_vecs(&shadow_ray, EPSILON_F);
	isp = add_vecs(&intersection->coord, &epsilon_shadow_ray);
	max_len = len_vector(&rt_info->light.coord, &intersection->coord)
		- EPSILON_F * 2;
	return (colide_s_ray_objs(objs, shadow_ray, isp, max_len));
}
