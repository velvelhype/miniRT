#include "render.h"
#include <stdlib.h>
#include <math.h>
#include "simple_operation.h"
#include "vector.h"

void	make_ref_dir(double ray_pl_dot, t_front_point *front_point, t_plane *pl)
{
	if (ray_pl_dot < (double)0)
		front_point->reflec_dir = mult_vecs(&pl->orient, -1);
	else
		front_point->reflec_dir = pl->orient;
}

t_front_point	colide_cam_ray_and_plane(t_vector r, t_vector *c, t_plane *pl)
{
	t_front_point	front_point;
	t_vector		c_cam;
	t_vector		multi;
	double			ray_pl_dot;
	double			t;

	c_cam = sub_vecs(c, &pl->coord);
	multi = mult_vecs(&r, -1);
	ray_pl_dot = dot_vecs(&multi, &pl->orient);
	front_point.length = 0;
	if (ray_pl_dot != (double)0)
	{
		t = dot_vecs(&c_cam, &pl->orient) / ray_pl_dot;
		if (t < 0)
			return (front_point);
		multi = mult_vecs(&r, t);
		front_point.coord = add_vecs(c, &multi);
		make_ref_dir(ray_pl_dot, &front_point, pl);
		normalize(&front_point.reflec_dir);
		front_point.length = len_vector(c, &front_point.coord);
		front_point.cam_dir = r;
		front_point.color = pl->color;
	}
	return (front_point);
}
