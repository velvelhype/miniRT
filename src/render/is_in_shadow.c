#include "miniRT.h"
#include <math.h>
#include "render.h"

bool	is_in_shadow(t_vector *shadow_ray, t_vector *is_plus, t_objs *objs, double max_len)
{
	t_front_point nearest_front;
	t_front_point new_front;

	nearest_front.length = 0;
	int i = 0;
	while (objs->spheres[i].is_end == false)
	{
		new_front = colide_cam_ray_and_sphere(*shadow_ray, is_plus, &objs->spheres[i]);
		if (new_front.length && new_front.length < max_len)
			return (TRUE);
		i++;
	}

	i = 0;
	while (objs->planes[i].is_end == false)
	{
		new_front = colide_cam_ray_and_plane(*shadow_ray, is_plus, &objs->planes[i]);
		if (new_front.length && new_front.length < max_len)
			return (TRUE);
		i++;
	}

	i = 0;
	while (objs->cylinders[i].is_end == false)
	{
		new_front = colide_cam_ray_and_cylinder(*shadow_ray, is_plus, &objs->cylinders[i]);
		if (new_front.length && new_front.length < max_len)
			return (TRUE);
		i++;
	}
	return (FALSE);
}