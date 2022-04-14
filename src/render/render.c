#include "miniRT.h"
#include "mlx.h"
#include "render.h"
#include "vector.h"
#include "math.h"

void	init_mlx(t_rt *rt_info, t_mlx *mlx)
{
	printf("config mlx\n");
    mlx->mlx_ptr = mlx_init();
    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, rt_info->coords.max_width, rt_info->coords.max_height, "Finally?");
    mlx->image = mlx_new_image(mlx->mlx_ptr, rt_info->coords.max_width, rt_info->coords.max_height);
}

void	make_screen(t_coord	*coords)
{
	// printf("%d\n", coords->cam_FOV);

	t_vector cam_to_sc_center = mult_vecs((&coords->cam_orient),
	coords->max_width / tan(coords->cam_FOV * 0.5 * M_PI / (double)180));
	print_vecs(&cam_to_sc_center);
	printf("dummy_make_screen\n");
	t_vector sc_center = add_vecs(&coords->cam_pos, &cam_to_sc_center);

	t_vector x_basis;  // x軸と並行なベクトル(スクリーンの世界)
	x_basis.x = cam_to_sc_center.z / sqrt(cam_to_sc_center.z * cam_to_sc_center.z + cam_to_sc_center.x * cam_to_sc_center.x);
	x_basis.y = 0;
	x_basis.z = -cam_to_sc_center.x / sqrt(cam_to_sc_center.z * cam_to_sc_center.z + cam_to_sc_center.x * cam_to_sc_center.x);
	t_vector y_basis;
	//TODO multed is ugly
	t_vector multed = mult_vecs(&cam_to_sc_center, -1);
	cross_vecs(&y_basis, &x_basis, &multed);
	normalize(&y_basis);

	if (coords->cam_orient.x == 0 && coords->cam_orient.y != 0 && coords->cam_orient.z == 0)
	{
		if (coords->cam_orient.y > 0)
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

	print_vecs(&coords->sc_bot_left);
	// init_vector(&coords->sc_bot_left, -1, -1, -8);
	// init_vector(&coords->sc_diff_x, (double)2 / coords->max_width, 0, 0);
	// init_vector(&coords->sc_diff_y, 0, (double)2 / coords->max_height, 0);
	coords->sc_diff_x = x_basis;
	coords->sc_diff_y = y_basis;
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
			double	color;
			color = detect_reflection(rt_info, x, y);
			mlx_pixel_put(rt_info->mlx_config.mlx_ptr, rt_info->mlx_config.win_ptr, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	//TODO replace with my_pixel_put
    mlx_loop(rt_info->mlx_config.mlx_ptr);
}