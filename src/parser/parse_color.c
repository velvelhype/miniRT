/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:39:25 by akito             #+#    #+#             */
/*   Updated: 2022/05/28 21:54:40 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_color	parse_color(char *vec3_str)
{
	t_color	result;
	char	**tokens;
	bool	flag[3];

	ft_memset(flag, true, sizeof(bool) * 3);
	tokens = ft_split(vec3_str, ',');
	if (tokens[0] == NULL || tokens[1] == NULL || tokens[2] == NULL
		|| tokens[3] != NULL)
		custom_exit("Vector3: invalid number of arguments");
	result.red = ft_my_atof(tokens[0], &flag[0]);
	result.green = ft_my_atof(tokens[1], &flag[1]);
	result.blue = ft_my_atof(tokens[2], &flag[2]);
	if (!flag[0] || !flag[1] || !flag[2])
		custom_exit("Vector3: invalid value");
	if (result.red < 0 || result.red > 255 || result.green < 0
		|| result.green > 255 || result.blue < 0 || result.blue > 255)
		custom_exit("Color: invalid color");
	ft_split_free(tokens);
	return (result);
}
