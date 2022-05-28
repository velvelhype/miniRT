/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:39:25 by akito             #+#    #+#             */
/*   Updated: 2022/05/28 20:58:01 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_color	parse_color(char *vec3_str)
{
	t_color	result;
	char	**tokens;

	tokens = ft_split(vec3_str, ',');
	if (tokens[0] == NULL || tokens[1] == NULL || tokens[2] == NULL
		|| tokens[3] != NULL)
		custom_exit("Vector3: invalid number of arguments");
	result.red = ft_atoi(tokens[0]);
	result.green = ft_atoi(tokens[1]);
	result.blue = ft_atoi(tokens[2]);
	if (result.red < 0 || result.red > 255 || result.green < 0
		|| result.green > 255 || result.blue < 0 || result.blue > 255)
		custom_exit("Color: invalid color");
	ft_split_free(tokens);
	return (result);
}
