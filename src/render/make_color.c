#include "miniRT.h"
#include <math.h>
#include "render.h"

int	make_light_color(int color, double br, int pt_color)
{
	int		red;
	int		green;
	int		blue;

	red = (((color >> 16) & 0xFF) * br * (((pt_color >> 16) & 0xFF) / 0xFF));
	green = (((color >> 8) & 0xFF) * br * (((pt_color >> 8) & 0xFF) / 0xFF));
	blue = ((color & 0xFF) * br * ((pt_color & 0xFF) / 0xFF));
	clamp(red, 0, 255);
	clamp(blue, 0, 255);
	clamp(green, 0, 255);
	return ((red << 16) | (green << 8) | blue);
}

int	ambient_light(t_light *lights, t_front_point *intersection)
{
	return (make_light_color(lights->amb_color, lights->amb_br, intersection->color));
}

int	diffuse_and_specular_reflection(t_vector *cam_dir, t_light *lights, t_front_point *intersection)
{
	int light = 0;
	//　diffuse : It looks well...
	t_vector light_dir;
	light_dir = sub_vecs(&lights[0].coord, &intersection->coord);
	normalize(&light_dir);
	double dot = dot_vecs(&intersection->reflec_dir, &light_dir);
	dot = clamp(dot, 0, 1);

	//dot * light_br * color
	if (dot > 0)
		light += make_light_color(lights->dif_color, lights->dif_br * dot, intersection->color);

	//　specular
	if (dot > 0)
	{
		t_vector	ref_dir;
		t_vector	inv_cam_dir;
		double		vr_dot;
		ref_dir = mult_vecs(&intersection->reflec_dir, dot * 2);
		ref_dir = sub_vecs(&ref_dir, &light_dir);
		normalize(&ref_dir);
		inv_cam_dir = mult_vecs(&cam_dir, -1);
		normalize(&inv_cam_dir);
		vr_dot = dot_vecs(&inv_cam_dir, &ref_dir);
		vr_dot = clamp(vr_dot, 0, 1);
		double shininess = 4;
		double lum_spe = pow(vr_dot, shininess);
		light += make_light_color(lights->spe_color, lights->spe_br * lum_spe, intersection->color);
		// BONUS: call detect_reflection recursively
	}
	return (light);
}