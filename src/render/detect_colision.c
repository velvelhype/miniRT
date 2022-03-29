#include "miniRT.h"
#include <math.h>
#include "render.h"

void	make_screen_point(t_vector *screen_point, t_coord *coords, int x, int y)
{
	init_vector(screen_point, 0, 0, 0);
	*screen_point = add_vecs(screen_point, &coords->sc_bot_left);
	t_vector mult;
	mult = mult_vecs(&coords->sc_diff_x, x);
	*screen_point = add_vecs(screen_point, &mult);
	mult = mult_vecs(&coords->sc_diff_y, y);
	*screen_point =  add_vecs(screen_point, &mult);
}

t_vector make_camdir(t_coord *coords, int x, int y)
{
	t_vector cam_dir;
	t_vector screen_point;
	make_screen_point(&screen_point, coords, x, y);
	cam_dir = sub_vecs(&screen_point, &coords->cam_pos);
	// printf("sc point:");
	// print_vecs(&screen_point);
	// print_vecs(&cam_dir);
	return (cam_dir);
}

double	detect_colision(t_rt *rt_info, int x, int y)
{
	// printf("detect colision\n");
	t_vector cam_dir = make_camdir(&rt_info->coords, x, y);
	// detect_colision to all objs
	// Lv1:cam_dir and sphere
	return (colide_ray_and_objs(&cam_dir, &rt_info->coords, &rt_info->objs));
	// Lv2:with shadow
	// Lv3:with light
	// Lv4:with color
	// Lv5:multiple sphere
	// back forefront info
	return 0;
}