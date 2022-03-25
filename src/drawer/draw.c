#include "miniRT.h"
#include "mlx.h"

void	draw(t_rt *rt_info)
{
	printf("draw\n");

    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 400, 400, "Finally?");

    void *image = mlx_new_image(mlx, 400, 400);
    
    // The following code goes here.

    mlx_loop(mlx);
	// int x;
	// int y;

	// x = 0;
	// y = 0;
	// while (y < rt_info->max_width)
	// {
	// 	while (x < rt_info->max_height)
	// 	{
	// 		// colide_detection();
	// 		// shading();
	// 		// lighting();
	// 		x++;
	// 	}
	// 	x = 0;
	// 	y++;
	// }
}