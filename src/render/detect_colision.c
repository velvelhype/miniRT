#include "miniRT.h"
#include <math.h>
#include "render.h"

void	make_screen_point(t_vector *screen_point, t_coord *coords, int x, int y)
{
	t_vector mult;

	init_vector(screen_point, 0, 0, 0);
	*screen_point = add_vecs(screen_point, &coords->sc_bot_left);
	mult = mult_vecs(&coords->sc_diff_x, x);
	*screen_point = add_vecs(screen_point, &mult);
	mult = mult_vecs(&coords->sc_diff_y, y);
	*screen_point =  add_vecs(screen_point, &mult);
}

t_vector make_cam_dir(t_coord *coords, int x, int y)
{
	t_vector cam_dir;
	t_vector screen_point;

	make_screen_point(&screen_point, coords, x, y);
	cam_dir = sub_vecs(&screen_point, &coords->camera.pos);
	// printf("sc point:");
	// print_vecs(&screen_point);
	// print_vecs(&cam_dir);
	return (cam_dir);
}

t_color	detect_reflection(t_rt *rt_info, int x, int y)
{
	t_vector cam_dir = make_cam_dir(&rt_info->coords, x, y);
	t_front_point intersection = colide_ray_and_objs(&cam_dir, &rt_info->coords.camera.pos, rt_info->objs);
	t_color	light = {0};

	if (intersection.length)
	{
		light = make_light_color(light, rt_info->light.color, rt_info->light.br_ratio, intersection.color);
		if (is_in_shadow(rt_info, &intersection, rt_info->objs))
			return (light);
		// diffuse : It looks well...
		t_vector light_dir;
		light_dir = sub_vecs(&rt_info->light.coord, &intersection.coord);
		normalize(&light_dir);
		double dot = dot_vecs(&intersection.reflec_dir, &light_dir);
		dot = clamp(dot, 0, 1);
		if (dot > 0)
			light = make_light_color(light, rt_info->light.color, rt_info->light.br_ratio * dot, intersection.color);
		if (dot > 0)
		{
			double lum_spe = specular_reflection(light_dir, dot, cam_dir, intersection);
			light = make_light_color(light, rt_info->light.color, rt_info->light.br_ratio * lum_spe, intersection.color);
			// BONUS: call detect_reflection recursively
		}
		return (light);
	}
	return (light);
}
