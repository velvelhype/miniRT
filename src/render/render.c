#include "miniRT.h"
#include "mlx.h"
#include "render.h"
#include "vector.h"

void	init_mlx(t_rt *rt_info, t_mlx *mlx)
{
	printf("config mlx\n");
    mlx->mlx_ptr = mlx_init();
    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, rt_info->coords.max_width, rt_info->coords.max_height, "Finally?");
    mlx->image = mlx_new_image(mlx->mlx_ptr, rt_info->coords.max_width, rt_info->coords.max_height);
}

void	make_screen(t_coord	*coords)
{
	// t_vector cam_pos_to_sc_center_dir = mult_vecs((&coords->cam_orient),
	// coords->max_width / tan(coords->cam_FOV * 0.5 * M_PI / 180));
	// printf("%d\n", coords->cam_FOV);
	// print_vecs(&cam_pos_to_sc_center_dir);
	printf("dummy_make_screen\n");
	init_vector(&coords->sc_bot_left, -200, -200, 20);
	init_vector(&coords->sc_diff_x, 1, 0, 0);
	init_vector(&coords->sc_diff_y, 0, 1, 0);
}

void	render(t_rt *rt_info)
{
	init_mlx(rt_info, &rt_info->mlx_config);
	make_screen(&rt_info->coords);
	printf("render\n");
	int x;
	int y;
	x = 0;
	y = 0;
	while (y < rt_info->coords.max_height)
	{
		while (x < rt_info->coords.max_width)
		{
			int	reflection;
			reflection = detect_colision(rt_info, x, y);
			if (reflection)
			{
				// make_color(reflection);
				mlx_pixel_put(rt_info->mlx_config.mlx_ptr, rt_info->mlx_config.win_ptr, x, y, 0xFF);
			}
			else
				mlx_pixel_put(rt_info->mlx_config.mlx_ptr, rt_info->mlx_config.win_ptr, x, y, 0x0);
			x++;
		}
		x = 0;
		y++;
	}
	//TODO replace with my_pixel_put
    mlx_loop(rt_info->mlx_config.mlx_ptr);
}