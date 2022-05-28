#include "miniRT.h"
#include <math.h>
#include "render.h"

void	init_col(t_color *color, int r, int g, int b)
{
	color->red = r;
	color->green = g;
	color->blue = b;
}

void	init_lum(t_luminance *lum, double r, double g, double b)
{
	lum->red = r;
	lum->green = g;
	lum->blue = b;
}

void	make_lum(t_luminance *lum, t_color *color, double ratio)
{
	lum->red += (double)color->red / (double)255 * ratio;
	lum->green += (double)color->green / (double)255 * ratio;
	lum->blue += (double)color->blue / (double)255 * ratio;
}

t_color	make_light_from_lum(t_luminance lum)
{
	t_color	light;

	light.red = (double)255 * clamp(lum.red, 0, 1);
	light.green = (double)255 * clamp(lum.green, 0, 1);
	light.blue = (double)255 * clamp(lum.blue, 0, 1);
	return (light);
}

double	spec_ref(t_vector l, double d, t_vector r, t_front_point is)
{
	t_vector	ref_dir;
	t_vector	inv_cam_dir;
	double		vr_dot;

	ref_dir = mult_vecs(&is.reflec_dir, d * 2);
	ref_dir = sub_vecs(&ref_dir, &l);
	normalize(&ref_dir);
	inv_cam_dir = mult_vecs(&r, -1);
	normalize(&inv_cam_dir);
	vr_dot = dot_vecs(&inv_cam_dir, &ref_dir);
	vr_dot = clamp(vr_dot, 0, 1);
	return (pow(vr_dot, SHININESS));
}
