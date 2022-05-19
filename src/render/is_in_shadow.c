#include "miniRT.h"
#include <math.h>
#include "render.h"

t_vector	make_shadow_ray(t_rt *rt_info, t_front_point *intersection)
{
	t_vector shadow_ray = sub_vecs(&rt_info->light.coord, &intersection->coord);
	normalize(&shadow_ray);
	return (shadow_ray);
}

bool	is_in_shadow(t_rt *rt_info, t_front_point *intersection ,t_list	*objs)
{
	t_vector shadow_ray = make_shadow_ray(rt_info, intersection);
	t_vector epsilon_shadow_ray = mult_vecs(&shadow_ray, EPSILON_F);
	t_vector insec_plus = add_vecs(&intersection->coord, &epsilon_shadow_ray);
	double max_len = len_vector(&rt_info->light.coord, &intersection->coord);

	t_front_point	new_front = {0};
	t_obj *obj;

	while (objs)
	{
		obj = objs->content;
		if (obj->type == SPHERE)
		{
			new_front = colide_cam_ray_and_sphere(shadow_ray, &insec_plus, objs->content);
		}
		if (obj->type == PLANE)
		{
			new_front = colide_cam_ray_and_plane(shadow_ray, &insec_plus, objs->content);
		}
		if (obj->type == CYLINDER)
		{
			new_front = colide_cam_ray_and_cylinder(shadow_ray, &insec_plus, objs->content);
			if (new_front.length != 0)
			{
				// printf("insec_plus  :");
				// print_vecs(&insec_plus);
				// printf("shadow_ray  :");
				// print_vecs(&shadow_ray);
				// printf("shadow point:");
				// print_vecs(&new_front.coord);
				// printf("%f\n", new_front.length);
				//if the length of shadow_point to cam
				// is longer than front_point_ to cam
				if (len_vector(&new_front.coord, &rt_info->light.coord) > new_front.length)
					return (FALSE);
			}
		}
		if (new_front.length && new_front.length < max_len)
		{
			return (TRUE);
		}
		objs = objs->next;
	}
	return (FALSE);
}
