/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:19:36 by akito             #+#    #+#             */
/*   Updated: 2022/05/28 22:02:13 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// <Identifier> <x>,<y>,<z> <camera-x>,<camera-y>,<camera-z> <FOV>
void	parse_camera(t_rt *rt_info, char **tokens, bool is_used)
{
	t_camera	*cam;
	bool		flag;

	flag = true;
	if (is_used)
		custom_exit("Camera: invalid number of arguments");
	cam = &rt_info->coords.camera;
	if (tokens[1] == NULL || tokens[2] == NULL || tokens[3] == NULL
		|| tokens[4] != NULL)
		custom_exit("Ambient light: invalid number of arguments");
	cam->pos = parse_vector3(tokens[1]);
	cam->orient = parse_normarized_vector3(tokens[2]);
	cam->fov = ft_my_atof(tokens[3], &flag);
	if (!flag)
		custom_exit("Camera: invalid FOV");
	if (cam->fov < 0 || cam->fov > 180)
		custom_exit("Camera: invalid FOV");
}
