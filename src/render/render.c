/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:32:50 by akito             #+#    #+#             */
/*   Updated: 2022/05/28 20:32:50 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "mlx.h"
#include "render.h"
#include "vector.h"
#include "math.h"
#include "hooks.h"

void	init_mlx(t_rt *rt_info, t_mlx *m)
{
	char	*a;
	double	x;
	double	y;

	x = rt_info->coords.max_width;
	y = rt_info->coords.max_height;
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, x, y, "miniRT");
	m->image = mlx_new_image(m->mlx_ptr, x, y);
	a = mlx_get_data_addr(m->image, &(m->pix_bits), &(m->line_len), &(m->endi));
	m->addr = a;
}

void	make_basis(t_coord	*c, t_vector	*sc_center, t_vector *multed)
{
	t_vector	c2sc;
	double		tan_sc;

	tan_sc = c->max_width / tan(c->camera.fov * 0.5 * M_PI / (double)180);
	c2sc = mult_vecs((&c->camera.orient), tan_sc);
	*sc_center = add_vecs(&c->camera.pos, &c2sc);
	c->sc_diff_x.x = c2sc.z / sqrt(c2sc.z * c2sc.z + c2sc.x * c2sc.x);
	c->sc_diff_x.y = 0;
	c->sc_diff_x.z = -c2sc.x / sqrt(c2sc.z * c2sc.z + c2sc.x * c2sc.x);
	*multed = mult_vecs(&c2sc, -1);
	cross_vecs(&c->sc_diff_y, &c->sc_diff_x, multed);
	normalize(&c->sc_diff_y);
}

void	make_screen(t_coord	*coo)
{
	t_vector	sc_center;
	t_vector	multed;

	make_basis(coo, &sc_center, &multed);
	if (!coo->camera.orient.x && coo->camera.orient.y && !coo->camera.orient.z)
	{
		if (coo->camera.orient.y > 0)
		{
			init_vector(&coo->sc_diff_x, -1, 0, 0);
			init_vector(&coo->sc_diff_y, 0, 0, -1);
		}
		else
		{
			init_vector(&coo->sc_diff_x, 1, 0, 0);
			init_vector(&coo->sc_diff_y, 0, 0, 1);
		}
	}
	multed = mult_vecs(&coo->sc_diff_x, coo->max_width / (double)2);
	coo->sc_bot_left = sub_vecs(&sc_center, &multed);
	multed = mult_vecs(&coo->sc_diff_y, coo->max_height / (double)2);
	coo->sc_bot_left = sub_vecs(&coo->sc_bot_left, &multed);
}

void	render(t_rt *rt_info, t_mlx *m_con)
{
	t_color	color;
	int		x;
	int		y;

	init_mlx(rt_info, m_con);
	make_screen(&rt_info->coords);
	x = 0;
	y = 0;
	while (y < rt_info->coords.max_height)
	{
		while (x < rt_info->coords.max_width)
		{
			color = detect_reflection(rt_info, x, y);
			my_pixel_put(m_con, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(m_con->mlx_ptr, m_con->win_ptr, m_con->image, 0, 0);
	register_hooks(m_con);
	mlx_loop(m_con->mlx_ptr);
}
