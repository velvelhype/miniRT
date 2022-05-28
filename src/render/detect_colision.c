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
	return (cam_dir);
}

t_color	detect_reflection(t_rt *rt_info, int x, int y)
{
	t_vector cam_dir = make_cam_dir(&rt_info->coords, x, y);
	t_front_point intersection = colide_ray_and_objs(&cam_dir, &rt_info->coords.camera.pos, rt_info->objs);
	t_color	light = {0};
	
	if (intersection.length)
	{
		t_luminance lum = {0};
		make_lum(&lum, &rt_info->ambient.color, rt_info->ambient.br_ratio);
		// printf("%f\n", lum.red);
		//
		if (!is_in_shadow(rt_info, &intersection, rt_info->objs))
		{
			// diffuse : It looks well...
			t_vector light_dir;
			light_dir = sub_vecs(&rt_info->light.coord, &intersection.coord);
			normalize(&light_dir);
			double dot = dot_vecs(&intersection.reflec_dir, &light_dir);
			dot = clamp(dot, 0, 1);
			if (dot > 0)
			{
				// add difuse luminance
				make_lum(&lum, &intersection.color, rt_info->light.br_ratio * dot);
				// printf("rev dot:%f\n", dot);
				//
			}
			if (dot > 0)
			{
				double lum_spe = specular_reflection(light_dir, dot, cam_dir, intersection);
				make_lum(&lum, &intersection.color, rt_info->light.br_ratio * lum_spe);
				// BONUS: call detect_reflection recursively
			}
		}
		return (make_light_from_lum(lum));
	}
	return (light);
}
