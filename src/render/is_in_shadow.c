#include "miniRT.h"
#include <math.h>
#include "render.h"

t_vector	make_shadow_ray(t_rt *rt_info, t_front_point *intersection)
{
	t_vector shadow_ray = sub_vecs(&rt_info->light.coord, &intersection->coord);
	// double max_len = len_vector(&rt_info->light.coord, &intersection->coord);
	shadow_ray = mult_vecs(&shadow_ray, EPSILON_F);
	return (shadow_ray);
}

bool	is_in_shadow(t_rt *rt_info, t_front_point *intersection ,t_list **objs)
{
	(void)rt_info;
	(void)intersection;
	(void)objs;
	// t_vector shadow_ray = make_shadow_ray(rt_info, intersection);
	// t_vector is_plus = add_vecs(&intersection->coord, &shadow_ray);
	// double max_len = len_vector(&rt_info->light.coord, &intersection->coord);

	//t_front_point	new_front;
	//t_front_point	nearest_front;
	//nearest_front.length = 0;
	//int i = 0;
	//while (objs->spheres[i].is_end == false)
	//{
	//	new_front = colide_cam_ray_and_sphere(shadow_ray, &is_plus, &objs->spheres[i]);
	//	if (new_front.length && new_front.length < max_len)
	//		return (TRUE);
	//	i++;
	//}

	//i = 0;
	//while (objs->planes[i].is_end == false)
	//{
	//	new_front = colide_cam_ray_and_plane(shadow_ray, &is_plus, &objs->planes[i]);
	//	if (new_front.length && new_front.length < max_len)
	//		return (TRUE);
	//	i++;
	//}

	//i = 0;
	//while (objs->cylinders[i].is_end == false)
	//{
	//	new_front = colide_cam_ray_and_cylinder(shadow_ray, &is_plus, &objs->cylinders[i]);
	//	if (new_front.length && new_front.length < max_len)
	//		return (TRUE);
	//	i++;
	//}
	return (false);
}
