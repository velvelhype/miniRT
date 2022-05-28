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
		front_point.coord = add_vecs(cam_pos, &multed);
		front_point.reflec_dir = sub_vecs(&front_point.coord, &sphere->coord);
		normalize(&front_point.reflec_dir);
		if (dot_vecs(&cam_dir, &front_point.reflec_dir) > 0)
			front_point.reflec_dir = mult_vecs(&front_point.reflec_dir, -1);
		front_point.length = len_vector(cam_pos, &front_point.coord);
		front_point.cam_dir = cam_dir;
		front_point.color = sphere->color;
	}
	return (front_point);
}

t_front_point	colide_cam_ray_and_plane(t_vector cam_dir, t_vector *cam_pos, t_plane *plane)
{
	t_front_point front_point;
	front_point.length = 0;
	
	t_vector c_cam = sub_vecs(cam_pos, &plane->coord);
	t_vector multed = mult_vecs(&cam_dir, -1);
	double ray_pl_dot = dot_vecs(&multed, &plane->orient);
	if (ray_pl_dot != (double)0)
	{
		double t = dot_vecs(&c_cam, &plane->orient) / ray_pl_dot;
		if (t < 0)
			return (front_point);
		multed = mult_vecs(&cam_dir, t);
		front_point.coord = add_vecs(cam_pos, &multed);
		if (ray_pl_dot <  (double)0)
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

t_front_point	colide_cam_ray_and_cylinder(t_vector cam_dir, t_vector *cam_pos, t_cylinder *cyl)
{
	t_front_point front_point;
	front_point.length = 0;

    double A, B, C, D;
	t_vector s;
	t_vector x;
	cross_vecs(&s, &cam_dir, &cyl->orient);
	A = norm(&s);
	A = square(A);
	cross_vecs(&s, &cam_dir, &cyl->orient);
	t_vector subbed = sub_vecs(cam_pos, &cyl->coord);
	cross_vecs(&x, &subbed, &cyl->orient);
	B = (double)2 * dot_vecs(&s, &x);
	t_vector c_cross;
	subbed = sub_vecs(cam_pos, &cyl->coord);
	cross_vecs(&c_cross, &subbed, &cyl->orient);
	C = norm(&c_cross);
	C = square(C) - square(cyl->diameter);
    D = square(B) - (double)4 * A * C;
	if (D < 0)
		return (front_point);
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
	if (height_outer >= 0 && height_outer <= cyl->height && t_outer >= 0) // if p_outer is not in behind the camera
	{
		front_point.coord = p_outer;
		t_vector multed = mult_vecs(&cyl->orient, height_outer);
		front_point.reflec_dir = sub_vecs(&center2p_outer, &multed);
		normalize(&front_point.reflec_dir);
		front_point.length = len_vector(cam_pos, &front_point.coord);
		front_point.cam_dir = cam_dir;
		front_point.color = cyl->color;
	}
	else if (height_inner >= 0 && height_inner <= cyl->height && t_inner >= 0)
	{
		front_point.coord = p_inner;
		t_vector multed = mult_vecs(&cyl->orient, height_inner);
		front_point.reflec_dir = sub_vecs(&multed, &center2p_inner);
		normalize(&front_point.reflec_dir);
		front_point.length = len_vector(cam_pos, &front_point.coord);
		front_point.cam_dir = cam_dir;
		front_point.color = cyl->color;
	}
	return (front_point);
}

t_front_point	colide_ray_and_objs(t_vector *cam_dir, t_vector *cam_pos, t_list	*objs)
{
	t_front_point nearest_front = {0};
	t_front_point	new_front = {0};
	nearest_front.length = 0;
	t_obj *obj;

	while (objs)
	{
		obj = objs->content;
		if (obj->type == SPHERE)
			new_front = colide_cam_ray_and_sphere(*cam_dir, cam_pos, objs->content);
		if (obj->type == PLANE)
			new_front = colide_cam_ray_and_plane(*cam_dir, cam_pos, objs->content);
		if (obj->type == CYLINDER)
			new_front = colide_cam_ray_and_cylinder(*cam_dir, cam_pos, objs->content);
		if (new_front.length)
			if (nearest_front.length == 0 || new_front.length < nearest_front.length)
				nearest_front = new_front;
		objs = objs->next;
	}
	return (nearest_front);
}
