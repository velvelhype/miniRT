#include "miniRT.h"
#include <math.h>
#include "render.h"

void	make_screen_point(t_vector *screen_point, t_coord *coords, int x, int y)
{
	t_vector	mult;

	init_vector(screen_point, 0, 0, 0);
	*screen_point = add_vecs(screen_point, &coords->sc_bot_left);
	mult = mult_vecs(&coords->sc_diff_x, x);
	*screen_point = add_vecs(screen_point, &mult);
	mult = mult_vecs(&coords->sc_diff_y, y);
	*screen_point = add_vecs(screen_point, &mult);
}

t_vector	make_cam_dir(t_coord *coords, int x, int y)
{
	t_vector	cam_dir;
	t_vector	screen_point;

	make_screen_point(&screen_point, coords, x, y);
	cam_dir = sub_vecs(&screen_point, &coords->camera.pos);
	return (cam_dir);
}

t_luminance	insec_lum(t_rt *rt_info, t_front_point	is, t_vector	cam_dir)
{
	t_luminance	lum;
	double		lum_spe;
	t_vector	light_dir;
	double		dot;

	init_lum(&lum, 0, 0, 0);
	make_lum(&lum, &rt_info->ambient.color, rt_info->ambient.br_ratio);
	if (!is_in_shadow(rt_info, &is, rt_info->objs))
	{
		light_dir = sub_vecs(&rt_info->light.coord, &is.coord);
		normalize(&light_dir);
		dot = dot_vecs(&is.reflec_dir, &light_dir);
		dot = clamp(dot, 0, 1);
		if (dot > 0)
		{
			make_lum(&lum, &is.color, rt_info->light.br_ratio * dot);
			lum_spe = spec_ref(light_dir, dot, cam_dir, is);
			make_lum(&lum, &is.color, rt_info->light.br_ratio * lum_spe);
		}
	}
	return (lum);
}

t_color	detect_reflection(t_rt *rt, int x, int y)
{
	t_vector		cam_dir;
	t_front_point	is;
	t_color			light;

	init_col(&light, 0, 0, 0);
	cam_dir = make_cam_dir(&rt->coords, x, y);
	is = colide_ray_and_objs(&cam_dir, &rt->coords.camera.pos, rt->objs);
	if (is.length)
		return (make_light_from_lum(insec_lum(rt, is, cam_dir)));
	return (light);
}
