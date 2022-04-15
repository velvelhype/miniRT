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
	cam_dir = sub_vecs(&screen_point, &coords->cam_pos);
	return (cam_dir);
}

int	detect_reflection(t_rt *rt_info, int x, int y)
{
	t_vector cam_dir = make_cam_dir(&rt_info->coords, x, y);
	t_front_point intersection = colide_ray_and_objs(&cam_dir, &rt_info->coords.cam_pos, &rt_info->objs);

	if (intersection.length)
	{
		int	light = 0;
		light += ambient_light(&rt_info->light, &intersection);
		// hard shadow
		t_vector shadow_ray = sub_vecs(&rt_info->light.coord, &intersection.coord);
		double max_len = len_vector(&rt_info->light.coord, &intersection.coord);
		shadow_ray = mult_vecs(&shadow_ray, epsilon);
		t_vector is_plus = add_vecs(&intersection.coord, &shadow_ray);
		if (is_in_shadow(&shadow_ray, &is_plus, &rt_info->objs, max_len))
			return (light);

		// diffuse : It looks well...
		t_vector light_dir;
		light_dir = sub_vecs(&rt_info->light.coord, &intersection.coord);
		normalize(&light_dir);
		double dot = dot_vecs(&intersection.reflec_dir, &light_dir);
		dot = clamp(dot, 0, 1);
		//dot * light_br * color
		if (dot > 0)
			light += make_light_color(rt_info->light.dif_color, rt_info->light.dif_br * dot, intersection.color);

		//　specular
		if (dot > 0)
		{
			t_vector	ref_dir;
			t_vector	inv_cam_dir;
			double		vr_dot;

			ref_dir = mult_vecs(&intersection.reflec_dir, dot * 2);
			ref_dir = sub_vecs(&ref_dir, &light_dir);
			normalize(&ref_dir);

			inv_cam_dir = mult_vecs(&cam_dir, -1);
			normalize(&inv_cam_dir);
			vr_dot = dot_vecs(&inv_cam_dir, &ref_dir);
			vr_dot = clamp(vr_dot, 0, 1);
			double shininess = 4;
			double lum_spe = pow(vr_dot, shininess);
			light += make_light_color(rt_info->light.spe_color, rt_info->light.spe_br * lum_spe, intersection.color);
			// BONUS: call detect_reflection recursively
		}
		return (light);
	}
	return 0;
}
