#include "miniRT.h"
#include <math.h>
#include "render.h"


//TODO it is different from phong's manipulation
t_color	make_light_color(t_color light, t_color color, double br, t_color pt_color)
{
	t_color res_color;

	res_color = light;
	res_color.red += color.red * br * (pt_color.red / 0xFF);
	res_color.green += color.green * br * (pt_color.green / 0xFF);
	res_color.blue += color.blue * br * (pt_color.blue / 0xFF);
	res_color.red = clamp(res_color.red, 0, 255);
	res_color.green = clamp(res_color.green, 0, 255);
	res_color.blue = clamp(res_color.blue, 0, 255);
	return (res_color);
}

double	specular_reflection(t_vector light_dir, double dot, t_vector cam_dir, t_front_point intersection)
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
	return (pow(vr_dot, SHININESS));
}
