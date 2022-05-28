/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:56:14 by akito             #+#    #+#             */
/*   Updated: 2022/05/28 20:56:14 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// <Identifier>  <x>,<y>,<z> <ratio>
// L -40.0,50.0,0.0 0.6 10,0,255
void	parse_light(t_rt *rt_info, char **tokens, bool is_used)
{
	if (is_used)
		custom_exit("Light: invalid number of arguments");
	if (tokens[1] == NULL || tokens[2] == NULL || tokens[3] != NULL)
		custom_exit("Light: invalid number of arguments");
	rt_info->light.coord = parse_vector3(tokens[1]);
	rt_info->light.br_ratio = parse_ratio(tokens[2]);
	rt_info->light.color = parse_color("255,255,255");
}
