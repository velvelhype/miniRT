/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:32:50 by akito             #+#    #+#             */
/*   Updated: 2022/05/28 20:32:50 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	my_pixel_put(t_mlx *mlx_config, int x, int y, t_color color)
{
	char	*dst;

	dst = mlx_config->addr
		+ (y * mlx_config->line_len + x * (mlx_config->pix_bits / 8));
	*(unsigned int *)dst = (color.red << 16) | (color.green << 8) | color.blue;
}
