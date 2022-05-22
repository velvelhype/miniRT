#include "miniRT.h"
#include <math.h>
#include "render.h"

void	make_lum(t_luminance *lum, t_color *color, double ratio)
{
	lum->red += (double)color->red / (double)255 * ratio;
	lum->green += (double)color->green / (double)255 * ratio;
	lum->blue += (double)color->blue / (double)255 * ratio;
}

t_color	make_light_from_lum(t_luminance lum)
{
	t_color light = {0};

	light.red = (double)255 * clamp(lum.red, 0, 1);
	light.green = (double)255 * clamp(lum.green, 0, 1);
	light.blue = (double)255 * clamp(lum.blue, 0, 1);
	return (light);
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
