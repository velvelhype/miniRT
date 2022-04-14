#include "miniRT.h"
#include <math.h>
#include "render.h"

bool	is_in_shadow(t_vector *cam_dir, t_vector *cam_pos, t_objs	*objs, double max_len)
{
	t_front_point nearest_front;
	t_front_point new_front;
 
	nearest_front.length = 0;
	int i = 0;
	while (objs->spheres[i].is_end == false)
	{
		new_front = colide_cam_ray_and_sphere(*cam_dir, cam_pos, &objs->spheres[i]);
		if (new_front.length && new_front.length < max_len)
			return (TRUE);
		i++;
	}

	i = 0;
	while (objs->planes[i].is_end == false)
	{
		new_front = colide_cam_ray_and_plane(*cam_dir, cam_pos, &objs->planes[i]);
		if (new_front.length && new_front.length < max_len)
			return (TRUE);
		i++;
	}

	i = 0;
	while (objs->cylinders[i].is_end == false)
	{
		new_front = colide_cam_ray_and_cylinder(*cam_dir, cam_pos, &objs->cylinders[i]);
		if (new_front.length && new_front.length < max_len)
			return (TRUE);
		i++;
	}

	return (FALSE);
}