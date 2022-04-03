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
		//TODO amb
		light += 50;
		//TODO diffuse
		//FIXME well i'm gonna dev this boy first
		//TODO specular
		//FIXME bugged
		t_vector light_dir;
		light_dir = sub_vecs(&rt_info->lights[0].coord, &intersection.coord);
		// light_dir = mult_vecs(&light_dir, -1);
		normalize(&light_dir);
		
		double dot = dot_vecs(&intersection.reflec_dir, &light_dir);
		if (dot > 1)
			dot = 1;
		if (dot < 0)
			dot = 0;
		printf("dot:%f\n", dot);
		if (dot > 0)
			light += dot * 150;
	
		// 0xFF00 * dot_vecs(intersection.reflec_dir, light_dir);
		// printf("%f\n", dot_vecs(&intersection.reflec_dir, &light_dir));
		return (light);
	}
	// TODO shadowing
	// Lv2:lighting
	// Lv3:with color
	// Lv4:multiple sphere
	// back forefront info
	return 0;
}