/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:33:53 by akito             #+#    #+#             */
/*   Updated: 2022/04/24 13:33:53 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	valid_file_extension(char *filename, char *ext)
{
	const char	*dot = ft_strrchr(filename, '.');

	if (!dot || dot == filename)
		return (false);
	return (ft_streq(dot, ext));
}

int	file_open(char *filename)
{
	int	fd;

	if (!valid_file_extension(filename, ".rt"))
		custom_exit("File extension must be .rt");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		custom_exit(NULL);
	return (fd);
}
