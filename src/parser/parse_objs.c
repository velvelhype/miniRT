/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:19:36 by akito             #+#    #+#             */
/*   Updated: 2022/05/28 20:57:16 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_sphere(t_rt *rt_info, char **tokens)
{
	t_sphere	sphere;
	bool		flag;

	flag = true;
	if (tokens[1] == NULL || tokens[2] == NULL || tokens[3] == NULL
		|| tokens[4] != NULL)
		custom_exit("Ambient light: invalid number of arguments");
	sphere.type = SPHERE;
	sphere.coord = parse_vector3(tokens[1]);
	sphere.diameter = ft_my_atof(tokens[2], &flag);
	if (!flag)
		custom_exit("Sphere: invalid diameter");
	sphere.color = parse_color(tokens[3]);
	ft_lstadd_back(&rt_info->objs, ft_lstnew(init_sphere(sphere)));
}

void	parse_plane(t_rt *rt_info, char **tokens)
{
	t_plane	plane;

	if (tokens[1] == NULL || tokens[2] == NULL || tokens[3] == NULL
		|| tokens[4] != NULL)
		custom_exit("Ambient light: invalid number of arguments");
	plane.type = PLANE;
	plane.coord = parse_vector3(tokens[1]);
	plane.orient = parse_normarized_vector3(tokens[2]);
	plane.color = parse_color(tokens[3]);
	ft_lstadd_back(&rt_info->objs, ft_lstnew(init_plane(plane)));
}

void	parse_cylinder(t_rt *rt_info, char **tokens)
{
	t_cylinder	cylinder;
	bool		flag;

	flag = true;
	if (tokens[1] == NULL || tokens[2] == NULL || tokens[3] == NULL
		|| tokens[5] == NULL || tokens[6] != NULL)
		custom_exit("Ambient light: invalid number of arguments");
	cylinder.type = CYLINDER;
	cylinder.coord = parse_vector3(tokens[1]);
	cylinder.orient = parse_normarized_vector3(tokens[2]);
	cylinder.diameter = ft_my_atof(tokens[3], &flag);
	if (!flag)
		custom_exit("Cylinder: invalid diameter");
	cylinder.height = ft_my_atof(tokens[4], &flag);
	if (!flag)
		custom_exit("Cylinder: invalid height");
	cylinder.color = parse_color(tokens[5]);
	ft_lstadd_back(&rt_info->objs, ft_lstnew(init_cylinder(cylinder)));
}

void	parse_objs(t_rt *rt_info, char **tokens, t_obj_type type)
{
	if (type == SPHERE)
		parse_sphere(rt_info, tokens);
	else if (type == PLANE)
		parse_plane(rt_info, tokens);
	else if (type == CYLINDER)
		parse_cylinder(rt_info, tokens);
	else
		custom_exit("Unknown object type");
}
