#include "miniRT.h"
#include <math.h>
#include "render.h"


//TODO it is different from phong's manipulation
int	make_light_color(int light, int color, double br, int pt_color)
{
	int		red;
	int		green;
	int		blue;

	red = (light >> 16) & 0xFF;
	green = (light >> 8) & 0xFF;
	blue = light & 0xFF;
	red += (((color >> 16) & 0xFF) * br * (((pt_color >> 16) & 0xFF) / 0xFF));
	green += (((color >> 8) & 0xFF) * br * (((pt_color >> 8) & 0xFF) / 0xFF));
	blue += ((color & 0xFF) * br * ((pt_color & 0xFF) / 0xFF));
	red = clamp(red, 0, 255);
	green = clamp(green, 0, 255);
	blue = clamp(blue, 0, 255);
	return ((red << 16) | (green << 8) | blue);
}

double	specular_reflection(t_vector light_dir, double dot, t_vector cam_dir, t_front_point intersection, t_rt *rt_info)
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
