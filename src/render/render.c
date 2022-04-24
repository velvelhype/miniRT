#include "miniRT.h"
#include "mlx.h"
#include "render.h"
#include "vector.h"
#include "math.h"

void	init_mlx(t_rt *rt_info, t_mlx *mlx)
{
	char	*a;
	printf("config mlx\n");
    mlx->mlx_ptr = mlx_init();
    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, rt_info->coords.max_width, rt_info->coords.max_height, "Finally?");
    mlx->image = mlx_new_image(mlx->mlx_ptr, rt_info->coords.max_width, rt_info->coords.max_height);
	a = mlx_get_data_addr(mlx->image, &(mlx->pix_bits), &(mlx->line_len), &(mlx->endi));
	mlx->addr = a;
}

void	make_screen(t_coord	*coords)
{
	t_vector cam_to_sc_center = mult_vecs((&coords->camera.orient),
	coords->max_width / tan(coords->camera.fov * 0.5 * M_PI / (double)180));
	printf("dummy_make_screen\n");
	t_vector sc_center = add_vecs(&coords->camera.pos, &cam_to_sc_center);
	t_vector x_basis;
	x_basis.x = cam_to_sc_center.z / sqrt(cam_to_sc_center.z * cam_to_sc_center.z + cam_to_sc_center.x * cam_to_sc_center.x);
	x_basis.y = 0;
	x_basis.z = -cam_to_sc_center.x / sqrt(cam_to_sc_center.z * cam_to_sc_center.z + cam_to_sc_center.x * cam_to_sc_center.x);
	t_vector y_basis;
	t_vector multed = mult_vecs(&cam_to_sc_center, -1);
	cross_vecs(&y_basis, &x_basis, &multed);
	normalize(&y_basis);
	if (coords->camera.orient.x == 0 && coords->camera.orient.y != 0 && coords->camera.orient.z == 0)
	{
		if (coords->camera.orient.y > 0)
		{
			init_vector(&x_basis, -1, 0, 0);
			init_vector(&y_basis, 0, 0, -1);
		}
		else
		{
			init_vector(&x_basis, 1, 0, 0);
			init_vector(&y_basis, 0, 0, 1);
		}
	}
	multed = mult_vecs(&x_basis, coords->max_width / (double)2);
	coords->sc_bot_left = sub_vecs(&sc_center, &multed);
	multed = mult_vecs(&y_basis, coords->max_height / (double)2);
	coords->sc_bot_left = sub_vecs(&coords->sc_bot_left, &multed);
	coords->sc_diff_x = x_basis;
	coords->sc_diff_y = y_basis;
}

void	render(t_rt *rt_info, t_mlx *mlx_config)
{
	printf("render\n");
	init_mlx(rt_info, mlx_config);
	make_screen(&rt_info->coords);
	int x;
	int y;
	x = 0;
	y = 0;
	while (y < rt_info->coords.max_height)
	{
		while (x < rt_info->coords.max_width)
		{
			t_color	color;
			color = detect_reflection(rt_info, x, y);
			my_pixel_put(mlx_config, x, y, color, &rt_info->coords);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(mlx_config->mlx_ptr, mlx_config->win_ptr, mlx_config->image, 0, 0);
    mlx_loop(mlx_config->mlx_ptr);
}
