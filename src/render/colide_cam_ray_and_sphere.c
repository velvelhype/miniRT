#include "render.h"
#include <stdlib.h>
#include <math.h>
#include "simple_operation.h"
#include "vector.h"

double	spr_discriminant(t_vector eye_dir, t_vector obj_to_eye, t_sphere *s)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = squared_norm(&eye_dir);
	b = 2 * dot_vecs(&eye_dir, &obj_to_eye);
	c = squared_norm(&obj_to_eye) - square(s->diameter);
	d = square(b) - 4 * a * c;
	return (quadratic_equation(a, b, c, d));
}

t_front_point	colide_cam_ray_and_sphere(t_vector r, t_vector *c, t_sphere *sp)
{
	t_vector		obj_to_eye;
	t_front_point	front_point;
	double			t;
	t_vector		multed;

	obj_to_eye = sub_vecs(c, &(sp->coord));
	front_point.length = 0;
	t = spr_discriminant(r, obj_to_eye, sp);
	if (t > 0)
	{
		multed = mult_vecs(&r, t);
		front_point.coord = add_vecs(c, &multed);
		front_point.reflec_dir = sub_vecs(&front_point.coord, &sp->coord);
		normalize(&front_point.reflec_dir);
		if (dot_vecs(&r, &front_point.reflec_dir) > 0)
			front_point.reflec_dir = mult_vecs(&front_point.reflec_dir, -1);
		front_point.length = len_vector(c, &front_point.coord);
		front_point.cam_dir = r;
		front_point.color = sp->color;
	}
	return (front_point);
}
