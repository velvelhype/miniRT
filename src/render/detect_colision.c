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
	cam_dir = sub_vecs(&screen_point, &coords->camera.pos);
	// printf("sc point:");
	// print_vecs(&screen_point);
	// print_vecs(&cam_dir);
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
	t_vector cam_dir = make_camdir(&rt_info->coords, x, y);
	// detect_reflection to all objs
	// Lv1:cam_dir and sphere
	t_front_point intersection = colide_ray_and_objs(&cam_dir, &rt_info->coords, &rt_info->objs);
	// TODO shading
	// make_color();
	if (intersection.length)
	{
		// TODO lighting
		// while(lights[i])
		// print_vecs(&rt_info->lights->coord);
		int	light = 0;
		// amb
		light += 50;
		//TODO diffuse : It looks well...
		t_vector light_dir;
		light_dir = sub_vecs(&rt_info->light.coord, &intersection.coord);
		// light_dir = mult_vecs(&light_dir, -1);
		normalize(&light_dir);
		double dot = dot_vecs(&intersection.reflec_dir, &light_dir);
		dot = clamp(dot);
		// printf("dot:%f\n", dot);
		if (dot > 0)
			light += dot * 100;
		// printf("%f\n", dot_vecs(&intersection.reflec_dir, &light_dir));
		//TODO specular
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
		}

		return (light);
	}
	// TODO shadowing
	// Lv3:with color
	// Lv4:multiple sphere
	return 0;
}
