/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:33:53 by akito             #+#    #+#             */
/*   Updated: 2022/04/24 13:33:53 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// <Identifier> <ratio> <R>,<G>,<B>
void	parse_ambient_light(t_rt *rt_info, char **tokens, bool is_used)
{
	if (is_used)
		custom_exit("Ambient light: invalid number of arguments");
	if (tokens[1] == NULL || tokens[2] == NULL || tokens[3] != NULL)
		custom_exit("Ambient light: invalid number of arguments");
	rt_info->ambient.br_ratio = parse_ratio(tokens[1]);
	rt_info->ambient.color = parse_color(tokens[2]);
}
