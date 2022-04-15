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

int	ambient_light(t_light *light, t_front_point *intersection)
{
	return (make_light_color(light->amb_color, light->amb_br, intersection->color));
}

int	specular_reflection(t_vector *light_dir, double dot, t_vector *cam_dir, t_front_point *intersection, t_rt *rt_info)
{

}

int	diffuse_and_specular_reflection(t_vector *cam_dir, t_light *light, t_front_point *intersection)
{

}