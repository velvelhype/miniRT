/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:10:12 by akito             #+#    #+#             */
/*   Updated: 2022/05/28 22:27:26 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parser.h"
#include "render.h"

int	main(int argc, char **argv)
{
	t_rt	rt_info;

	rt_info.objs = NULL;
	if (argc != 2)
		custom_exit("Invalid number of arguments");
	parse(argv[1], &rt_info);
	rt_info.coords.max_height = WINDOW_HEIGHT;
	rt_info.coords.max_width = WINDOW_WIDTH;
	render(&rt_info, &rt_info.mlx_config);
}
