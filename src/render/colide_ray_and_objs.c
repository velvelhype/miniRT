#include "render.h"
#include <stdlib.h>
#include <math.h>
#include "simple_operation.h"
#include "vector.h"

double	sphere_discriminant(t_vector eye_dir, t_vector obj_to_eye, t_sphere *spr)
{
    double A, B, C, D;

    A = squared_norm(&eye_dir);
    B = 2 * dot_vecs(&eye_dir, &obj_to_eye);
    C = squared_norm(&obj_to_eye) - square(spr->diameter);
    D = square(B) - 4 * A * C;
	return (quadratic_equation(A, B, C, D));
}

t_front_point	colide_cam_ray_and_sphere(t_vector cam_dir, t_vector *cam_pos, t_sphere *sphere)
{
	t_vector obj_to_eye = sub_vecs(cam_pos, &(sphere->coord));
	t_front_point front_point;

	front_point.length = 0;
	double t = sphere_discriminant(cam_dir, obj_to_eye, sphere);
	if (t > 0)
	{
		// p = cam_pos + t * cam_dir
		t_vector multed = mult_vecs(&cam_dir, t);
		front_point.coord = add_vecs(cam_pos, &multed);
		front_point.reflec_dir = sub_vecs(&front_point.coord, &sphere->coord);
		normalize(&front_point.reflec_dir);
		front_point.length = len_vector(cam_pos, &front_point.coord);
		front_point.cam_dir = cam_dir;
	}
	return (front_point);
}

t_front_point	colide_cam_ray_and_plane(t_vector cam_dir, t_vector *cam_pos, t_plane *plane)
{
	t_front_point front_point;
	front_point.length = 0;

	if (dot_vecs(&cam_dir, &plane->orient))
	{
		t_vector subbed = sub_vecs(&plane->coord, cam_pos);
		double t = dot_vecs(&subbed, &plane->orient);
		// printf("%f\n", t);
		t /= dot_vecs(&cam_dir, &plane->orient);
		t *= -1;

		t_vector multed = mult_vecs(&cam_dir, t);
		front_point.coord = add_vecs(cam_pos, &multed);
		front_point.reflec_dir = plane->orient;
		front_point.length = len_vector(cam_pos, &front_point.coord);
		front_point.cam_dir = cam_dir;
	}
	return (front_point);
}

t_front_point	colide_cam_ray_and_cylinder(t_vector cam_dir, t_vector *cam_pos, t_cylinder *cylinder)
{
    double A, B, C, D;
	// 𝑥=𝑠𝑥+𝑡𝑑𝑥
	// 中心位置 𝐩c→=(𝑐𝑥,𝑐𝑦,𝑐𝑧)
	// 𝑚𝑥=𝑠𝑥–𝑐𝑥
	double mx = cam_pos->x - cylinder->coord.x;
	// 𝑚𝑧=𝑠𝑧–𝑐𝑧
	double mz = cam_pos->z - cylinder->coord.z;
	// 𝐴=𝑑𝑥^2+𝑑𝑧^2;
    A = square(cam_dir.x) + square(cam_dir.z);
	// 𝐵=2(𝑑𝑥𝑚𝑥+𝑑𝑧𝑚𝑧);
    B = 2 * (cam_dir.x * mx + cam_dir.z * mz);
	// 𝐶=(𝑚𝑥^2+𝑚𝑧^2)–𝑟^2;
    C = square(mx) + square(mz) - square(cylinder->diameter);
    D = square(B) - 4 * A * C;
	double t = quadratic_equation(A, B, C, D);
	t_front_point front_point;
	front_point.length = 0;
	if (t > 0)
	{
		// p = cam_pos + t * cam_dir
		t_vector multed = mult_vecs(&cam_dir, t);
		front_point.coord = add_vecs(cam_pos, &multed);
		//reflec vec cyl
		front_point.reflec_dir.x = 2 * (front_point.coord.x - cylinder->coord.x);
		front_point.reflec_dir.y = 0;
		front_point.reflec_dir.z = 2 * (front_point.coord.z - cylinder->coord.z);
		//
		normalize(&front_point.reflec_dir);
		front_point.length = len_vector(cam_pos, &front_point.coord);
		front_point.cam_dir = cam_dir;
	}
	return (front_point);
}

t_front_point	colide_ray_and_objs(t_vector *cam_dir, t_vector *cam_pos, t_objs	*objs)
{
	t_front_point nearest_front;
	t_front_point new_front;
 
	nearest_front.length = 0;
	int i = 0;
	while (objs->spheres[i].is_end == false)
	{
		new_front = colide_cam_ray_and_sphere(*cam_dir, cam_pos, &objs->spheres[i]);
		if (new_front.length)
			if (nearest_front.length == 0 || new_front.length < nearest_front.length)
				nearest_front = new_front;
		i++;
	}

	i = 0;
	while (objs->planes[i].is_end == false)
	{
		new_front = colide_cam_ray_and_plane(*cam_dir, cam_pos, &objs->planes[i]);
		if (new_front.length)
		{
			if (nearest_front.length == 0 || new_front.length < nearest_front.length)
				{
					nearest_front = new_front;
				}
		}
		i++;
	}

	i = 0;
	while (objs->cylinders[i].is_end == false)
	{
		new_front = colide_cam_ray_and_cylinder(*cam_dir, cam_pos, &objs->cylinders[i]);
		if (new_front.length)
		{
			if (nearest_front.length == 0 || new_front.length < nearest_front.length)
				{
					nearest_front = new_front;
				}
		}
		i++;
	}
	return (nearest_front);

	// while (objs->cylinders)
	// {
	// 	objs->cylinders++;
	// }
}

//TODO colide_shadow_ray_and_objs