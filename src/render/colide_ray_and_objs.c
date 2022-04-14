#include "render.h"
#include <stdlib.h>
#include <math.h>
#include "ternary_operation.h"
#include "vector.h"

double quadratic_equation(t_vector eye_dir, t_vector obj_to_eye, t_sphere *spr)
{
    double A, B, C, D;

    A = squared_norm(&eye_dir);
    B = 2 * dot_vecs(&eye_dir, &obj_to_eye);
    C = squared_norm(&obj_to_eye) - pow(spr->diameter, 2);
    D = pow(B, 2) - 4 * A * C;
	double	t;
	t = 0;
	if (D == 0)
		t = -B  / (2 * A);
	if (D > 0)
	{
		double t1 = (-B + sqrt(D)) / (2 * A);
		double t2 = (-B - sqrt(D)) / (2 * A);
		if (t1 > 0)
			t = t1;
		if (t2 > 0 && t2 < t)
			t = t2;
		// t = max(t1, t2);

		// printf("t:%f\n", t);
	}
	return (t);
}

t_front_point	colide_cam_ray_and_sphere(t_vector cam_dir, t_coord *coords, t_sphere *sphere)
{
	t_vector obj_to_eye = sub_vecs(&(coords->camera.pos), &(sphere->coord));
	print_vecs(&sphere->coord);
	t_front_point front_point;
	front_point.length = 0;
	// printf (" %f\n", quadratic_equation(cam_dir, obj_to_eye, objs->spheres));
	double t = quadratic_equation(cam_dir, obj_to_eye, sphere);
	if (t > 0)
	{
		// p = cam_pos + t * cam_dir
		t_vector multed = mult_vecs(&cam_dir, t);
		front_point.coord = add_vecs(&coords->camera.pos, &multed);
		front_point.reflec_dir = sub_vecs(&front_point.coord, &sphere->coord);
		normalize(&front_point.reflec_dir);
		front_point.length = len_vector(&coords->camera.pos, &front_point.coord);
		front_point.cam_dir = cam_dir;
	}
	return (front_point);
}

t_front_point	colide_ray_and_objs(t_vector *cam_dir, t_coord *coords, t_objs	*objs)
{
	//colide with all objs
	t_front_point nearest_front;
	t_front_point new_front;
	int i = 0;

	nearest_front.length = 0;
	while (objs->spheres[i].is_end == 0)
	{
		// printf("i: %d\n", i);
		// TODOchange sphere_pos
		new_front = colide_cam_ray_and_sphere(*cam_dir, coords, &objs->spheres[i]);
		if (new_front.length)
			if (nearest_front.length == 0 || new_front.length < nearest_front.length)
				nearest_front = new_front;
		i++;
	}
	return (nearest_front);
	// while (objs->planes)
	// {
	// 	objs->planes++;
	// }
	// while (objs->cylinders)
	// {
	// 	objs->cylinders++;
	// }
}
