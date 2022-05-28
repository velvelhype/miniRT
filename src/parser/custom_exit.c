/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:38:39 by akito             #+#    #+#             */
/*   Updated: 2022/05/28 20:38:39 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <errno.h>
#include <stdio.h>

void	custom_exit(char *msg)
{
	if (errno != 0)
	{
		ft_putendl_fd("Error", STDERR);
		perror("");
	}
	else
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd(msg, STDERR);
	}
	exit(EXIT_FAILURE);
}
