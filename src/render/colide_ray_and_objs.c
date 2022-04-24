#include "render.h"
#include <stdlib.h>
#include <math.h>
#include "simple_operation.h"
#include "vector.h"

double	sphere_discriminant(t_vector eye_dir, t_vector obj_to_eye, t_sphere *spr)
{
	double	A;
	double	B;
	double	C;
	double	D;

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
		t_vector multed = mult_vecs(&cam_dir, t);
		front_point.coord = add_vecs(&coords->camera.pos, &multed);
		front_point.reflec_dir = sub_vecs(&front_point.coord, &sphere->coord);
		normalize(&front_point.reflec_dir);
		front_point.length = len_vector(&coords->camera.pos, &front_point.coord);
		front_point.cam_dir = cam_dir;
		front_point.color = sphere->color;
	}
	return (front_point);
}

t_front_point	colide_cam_ray_and_plane(t_vector cam_dir, t_vector *cam_pos, t_plane *plane)
{
	t_front_point front_point;

	front_point.length = 0;
	if (dot_vecs(&cam_dir, &plane->orient) > 0)
	{
		t_vector sub = sub_vecs(&plane->coord, cam_pos);
		double t = dot_vecs(&sub, &plane->orient);
		t /= dot_vecs(&cam_dir, &plane->orient);
		t_vector multed = mult_vecs(&cam_dir, t);
		front_point.coord = add_vecs(cam_pos, &multed);
		// judge front or back
		if (dot_vecs(&cam_dir, &plane->orient) > 0)
			front_point.reflec_dir = mult_vecs(&plane->orient, -1);
		else
			front_point.reflec_dir = plane->orient;
		normalize(&front_point.reflec_dir);
		front_point.length = len_vector(cam_pos, &front_point.coord);
		front_point.cam_dir = cam_dir;
		front_point.color = plane->color;
	}
	return (front_point);
}

//TODO cylinder shadow is wrong along the x axis
t_front_point	colide_cam_ray_and_cylinder(t_vector cam_dir, t_vector *cam_pos, t_cylinder *cyl)
{
    double A, B, C, D;
	t_vector s;
	t_vector x;
	cross_vecs(&s, &cam_dir, &cyl->orient);
	A = norm(&s);
	A = square(A);
	cross_vecs(&s, &cam_dir, &cyl->orient);
	t_vector subbed = sub_vecs(cam_pos, &cyl->coord);
	cross_vecs(&x, &subbed, &cyl->orient);
	B = 2 * dot_vecs(&s, &x);
	t_vector c_cross;
	subbed = sub_vecs(cam_pos, &cyl->coord);
	cross_vecs(&c_cross, &subbed, &cyl->orient);
	C = norm(&c_cross);
	C = square(C) - square(cyl->diameter);
    D = square(B) - (double)4 * A * C;

	t_front_point front_point;
	if (D < 0)
	{
		front_point.length = 0;
		return (front_point);
	}

	// レイと円筒との距離を求める
	double t_outer = (-B - sqrt(D)) / ((double)2 * A);  // 円筒の外側
	double t_inner = (-B + sqrt(D)) / ((double)2 * A);  // 円筒の内側

	// レイと縦に無限に伸びる円筒との交点
	t_vector multed = mult_vecs(&cam_dir, t_outer);
	t_vector p_outer = add_vecs(cam_pos, &multed);
			 multed = mult_vecs(&cam_dir, t_inner);
	t_vector p_inner = add_vecs(cam_pos, &multed);

	t_vector center2p_outer = sub_vecs(&p_outer, &cyl->coord);
	t_vector center2p_inner = sub_vecs(&p_inner, &cyl->coord);

	// 底面から交点までの高さ
	double height_outer = dot_vecs(&center2p_outer, &cyl->orient);
	double height_inner = dot_vecs(&center2p_inner, &cyl->orient);
	if (height_outer >= 0 && height_outer <= cyl->height)
	{
		front_point.coord = p_outer;
		t_vector multed = mult_vecs(&cyl->orient, height_outer);
		front_point.reflec_dir = sub_vecs(&center2p_outer, &multed);
		normalize(&front_point.reflec_dir);
		front_point.length = len_vector(&cam_pos, &front_point.coord);
		front_point.cam_dir = cam_dir;
		front_point.color = cyl->color;
	}
	else if (height_inner >= 0 && height_inner <= cyl->height)
	{
		front_point.coord = p_inner;
		t_vector multed = mult_vecs(&cyl->orient, height_inner);
		front_point.reflec_dir = sub_vecs(&multed, &center2p_inner);
		normalize(&front_point.reflec_dir);
		front_point.length = len_vector(&cam_pos, &front_point.coord);
		front_point.cam_dir = cam_dir;
		front_point.color = cyl->color;
	}
	else
	{
		front_point.length = 0;
	}

	return (front_point);
}

// only along y axis
// t_front_point	colide_cam_ray_and_cylinder(t_vector cam_dir, t_vector *cam_pos, t_cylinder *cylinder)
// {
//     double A, B, C, D;
// 	// 𝑥=𝑠𝑥+𝑡𝑑𝑥
// 	// 中心位置 𝐩c→=(𝑐𝑥,𝑐𝑦,𝑐𝑧)
// 	// 𝑚𝑥=𝑠𝑥–𝑐𝑥
// 	double mx = cam_pos->x - cylinder->coord.x;
// 	// 𝑚𝑧=𝑠𝑧–𝑐𝑧
// 	double mz = cam_pos->z - cylinder->coord.z;
// 	// 𝐴=𝑑𝑥^2+𝑑𝑧^2;
//     A = square(cam_dir.x) + square(cam_dir.z);
// 	// 𝐵=2(𝑑𝑥𝑚𝑥+𝑑𝑧𝑚𝑧);
//     B = 2 * (cam_dir.x * mx + cam_dir.z * mz);
// 	// 𝐶=(𝑚𝑥^2+𝑚𝑧^2)–𝑟^2;
//     C = square(mx) + square(mz) - square(cylinder->diameter);
//     D = square(B) - (double)4 * A * C;
// 	double t = quadratic_equation(A, B, C, D);
// 	t_front_point front_point;
// 	front_point.length = 0;
// 	// height
// 	if (t > 0)
// 	{
// 		t_vector multed = mult_vecs(&cam_dir, t);
// 		front_point.coord = add_vecs(cam_pos, &multed);

// 		// replace mod to len_vector(front_point, intersection);
// 		if (cylinder->height < mod(front_point.coord.y - cylinder->coord.y))
// 			return (front_point);
// 		front_point.reflec_dir.x = (double)2 * (front_point.coord.x - cylinder->coord.x);
// 		front_point.reflec_dir.y = 0;
// 		front_point.reflec_dir.z = (double)2 * (front_point.coord.z - cylinder->coord.z);
// 		normalize(&front_point.reflec_dir);
// 		front_point.length = len_vector(cam_pos, &front_point.coord);
// 		front_point.cam_dir = cam_dir;
// 		front_point.color = cylinder->color;
// 	}
// 	return (front_point);
// }

t_front_point	colide_ray_and_objs(t_vector *cam_dir, t_vector *cam_pos, t_lst	*objs)
{
	t_front_point nearest_front;
	t_front_point new_front;

	nearest_front.length = 0;
	while (objs)
	{
		if (objs->content.type == SPHERE)
			new_front = colide_cam_ray_and_sphere(*cam_dir, cam_pos, &objs->content);
		if (objs->content.type == PLANE)
			new_front = colide_cam_ray_and_plane(*cam_dir, cam_pos, &objs->content);
		if (objs->content.type == CYLINDER)
			new_front = colide_cam_ray_and_cylinder(*cam_dir, cam_pos, &objs->content);
		if (new_front.length)
			if (nearest_front.length == 0 || new_front.length < nearest_front.length)
				nearest_front = new_front;
		objs = objs->next;
	}
	return (nearest_front);
}

// t_front_point	colide_ray_and_objs(t_vector *cam_dir, t_vector *cam_pos, t_objs	*objs)
// {
// 	t_front_point nearest_front;
// 	t_front_point new_front;

// 	nearest_front.length = 0;
// 	int i = 0;
// 	while (objs->spheres[i].is_end == false)
// 	{
// 		new_front = colide_cam_ray_and_sphere(*cam_dir, cam_pos, &objs->spheres[i]);
// 		if (new_front.length)
// 			if (nearest_front.length == 0 || new_front.length < nearest_front.length)
// 				nearest_front = new_front;
// 		i++;
// 	}

// 	i = 0;
// 	while (objs->planes[i].is_end == false)
// 	{
// 		new_front = colide_cam_ray_and_plane(*cam_dir, cam_pos, &objs->planes[i]);
// 		if (new_front.length)
// 		{
// 			if (nearest_front.length == 0 || new_front.length < nearest_front.length)
// 				{
// 					nearest_front = new_front;
// 				}
// 		}
// 		i++;
// 	}

// 	i = 0;
// 	while (objs->cylinders[i].is_end == false)
// 	{
// 		new_front = colide_cam_ray_and_cylinder(*cam_dir, cam_pos, &objs->cylinders[i]);
// 		if (new_front.length)
// 		{
// 			if (nearest_front.length == 0 || new_front.length < nearest_front.length)
// 				{
// 					nearest_front = new_front;
// 				}
// 		}
// 		i++;
// 	}
// 	return (nearest_front);
// }
