#include "miniRT.h"
#include "mlx.h"

void	init_mlx(t_rt *rt_info)
{
	printf("config mlx\n");
    rt_info->mlx_ptr = mlx_init();
    rt_info->win_ptr = mlx_new_window(rt_info->mlx_ptr, rt_info->max_width, rt_info->max_height, "Finally?");
    rt_info->image = mlx_new_image(rt_info->mlx_ptr, rt_info->max_width, rt_info->max_height);
}

void	draw(t_rt *rt_info)
{
	init_mlx(rt_info);
	printf("draw\n");
	int x;
	int y;
	x = 0;
	y = 0;
	while (y < rt_info->max_height)
	{
		while (x < rt_info->max_width)
		{
			// colide_detection();
			// shading();
			// lighting();
			mlx_pixel_put(rt_info->mlx_ptr, rt_info->win_ptr, x, y, 0xFF);
			x++;
		}
		x = 0;
		y++;
	}
	//TODO replace with my_pixel_put
    mlx_loop(rt_info->mlx_ptr);
}