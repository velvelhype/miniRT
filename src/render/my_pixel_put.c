#include "miniRT.h"

void	put_pix(t_mlx *mlx_config, int x, int y, int color, t_coord *coords)
{
	char	*dst;

	dst = mlx_config->addr + (y * mlx_config->line_len + x * (mlx_config->pix_bits / 8));
	*(unsigned int *)dst = color;
}

void	my_pixel_put(t_mlx *mlx_config, int x, int y, int color, t_coord *coords)
{
	// if (x < 0 || x > WIDTH)
	if (x < 0 || x > coords->max_width)
		return ;
	// if (y < 0 || y > HEIGHT)
	if (y < 0 || y > coords->max_height)
		return ;
	put_pix(mlx_config, x, y, color, coords);
}