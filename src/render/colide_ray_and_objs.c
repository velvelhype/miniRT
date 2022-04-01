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
	// t = -B + root(D) / 2 * A;
	// t = -B - root(D) / 2 * A;
	t = 0;
	if (D == 0)
		t = B * -1 / (2 * A);
	if (D > 0)
		t  = max((B * -1 + sqrt(D)) / (2 * A), (B * -1 - sqrt(D)) / (2 * A));
	return (t);
}

t_front_point	colide_cam_ray_and_sphere(t_vector cam_dir, t_coord *coords, t_sphere *sphere)
{
	t_vector obj_to_eye = sub_vecs(&(coords->cam_pos), &(sphere->coord));
	t_front_point front_point;

	front_point.length = 0;
	// printf (" %f\n", quadratic_equation(cam_dir, obj_to_eye, objs->spheres));
	double t = quadratic_equation(cam_dir, obj_to_eye, sphere);
	if (t)
	{
		// p = cam_pos + t * cam_dir
		t_vector multed = mult_vecs(&cam_dir, t);
		front_point.coord = add_vecs(&coords->cam_pos, &multed);
		front_point.length = len_vector(&coords->cam_pos, &front_point.coord);
		front_point.reflec_dir = sub_vecs(&front_point.coord, &sphere->coord);
		normalize(&front_point.reflec_dir);
	}
	return (front_point);
}

t_front_point	colide_ray_and_objs(t_vector *cam_dir, t_coord *coords, t_objs	*objs)
{
	//colide with all objs
	int i = 0;
	while (objs->spheres[i].is_end == 0)
	{
		// print_vecs(&objs->spheres->coord);
		return (colide_cam_ray_and_sphere(*cam_dir, coords, &objs->spheres[i]));
		i++;
	}
	// while (objs->planes)
	// {
	// 	objs->planes++;
	// }
	// while (objs->cylinders)
	// {
	// 	objs->cylinders++;
	// }
}