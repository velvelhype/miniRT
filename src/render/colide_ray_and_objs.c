#include "render.h"
#include <stdlib.h>
#include <math.h>
#include "simple_operation.h"
#include "vector.h"

t_front_point	colide_ray_and_objs(t_vector *r, t_vector *c, t_list	*objs)
{
	t_front_point	nearest_front;
	t_front_point	f;
	t_obj			*obj;

	nearest_front.length = 0;
	f.length = 0;
	nearest_front.length = 0;
	while (objs)
	{
		obj = objs->content;
		if (obj->type == SPHERE)
			f = colide_cam_ray_and_sphere(r, c, objs->content);
		if (obj->type == PLANE)
			f = colide_cam_ray_and_plane(r, c, objs->content);
		if (obj->type == CYLINDER)
			f = colide_ray_and_cyl(r, c, objs->content);
		if (f.length)
			if (nearest_front.length == 0 || f.length < nearest_front.length)
				nearest_front = f;
		objs = objs->next;
	}
	return (nearest_front);
}
