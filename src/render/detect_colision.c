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

t_vector make_cam_dir(t_coord *coords, int x, int y)
{
	t_vector cam_dir;
	t_vector screen_point;
	make_screen_point(&screen_point, coords, x, y);
	cam_dir = sub_vecs(&screen_point, &coords->cam_pos);
	return (cam_dir);
}

double	clamp(double val)
{
	if (val > 1)
		val = 1;
	if (val < 0)
		val = 0;
	return (val);
}

int	detect_reflection(t_rt *rt_info, int x, int y)
{
	// printf("detect colision\n");
	t_vector cam_dir = make_cam_dir(&rt_info->coords, x, y);
	// print_vecs(&cam_dir);
	// detect_reflection to all objs
	t_front_point intersection = colide_ray_and_objs(&cam_dir, &rt_info->coords.cam_pos, &rt_info->objs);

	// TODO　同じ位置なら弾く
	if (intersection.length)
	{
		int	light = 0;
		// amb
		light += 70;
		// TODO hard shadowing
		// make
		t_vector shadow_ray = sub_vecs(&rt_info->lights[0].coord, &intersection.coord);
		double max_len = len_vector(&rt_info->lights[0].coord, &intersection.coord);
		// norm(&shadow_ray);
		shadow_ray = mult_vecs(&shadow_ray, epsilon);
		t_vector coord_plus = add_vecs(&intersection.coord, &shadow_ray);
		if (is_in_shadow(&shadow_ray, &coord_plus, &rt_info->objs, max_len))
			return (light);

		// print_vecs(&intersection.coord);

		//　diffuse : It looks well...
		t_vector light_dir;
		light_dir = sub_vecs(&rt_info->lights[0].coord, &intersection.coord);
		// light_dir = mult_vecs(&light_dir, -1);
		normalize(&light_dir);
		// print_vecs(&light_dir);
		double dot = dot_vecs(&intersection.reflec_dir, &light_dir);
		// printf("%f\n", dot);
		dot = clamp(dot);
		if (dot > 0)
			light += dot * 80;

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
			vr_dot = clamp(vr_dot);
			double shininess = 4;
			double lum_spe = pow(vr_dot, shininess);
			// printf("%f\n", lum_spe);
			light += 100 * lum_spe;
			// TODO BONUS: re rayTrace: call rayTrace recursivelt
		}
		return (light);
	}
	return 0;
}