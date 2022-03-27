#include "miniRT.h"
#include "mlx.h"
#include "render.h"

void	init_mlx(t_rt *rt_info, t_mlx *mlx)
{
	printf("config mlx\n");
    mlx->mlx_ptr = mlx_init();
    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, rt_info->coords.max_width, rt_info->coords.max_height, "Finally?");
    mlx->image = mlx_new_image(mlx->mlx_ptr, rt_info->coords.max_width, rt_info->coords.max_height);
}

void	render(t_rt *rt_info)
{
	init_mlx(rt_info, &rt_info->mlx_config);
	printf("render\n");
	int x;
	int y;
	x = 0;
	y = 0;
	while (y < rt_info->coords.max_height)
	{
		while (x < rt_info->coords.max_width)
		{
			detect_colision(rt_info, x, y);
			// shading();
			// lighting();
			mlx_pixel_put(rt_info->mlx_config.mlx_ptr, rt_info->mlx_config.win_ptr, x, y, 0xFF);
			x++;
		}
		x = 0;
		y++;
	}
	//TODO replace with my_pixel_put
    mlx_loop(rt_info->mlx_config.mlx_ptr);
}