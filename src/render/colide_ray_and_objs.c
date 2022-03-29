#include "render.h"
#include <stdlib.h>
#include <math.h>

#include "vector.h"

float quadratic_equation(t_vector eye_dir, t_vector obj_to_eye, t_sphere *spr)
{
    float A, B, C, D;

    A = squared_norm(&eye_dir);
    B = 2 * dot_vecs(&eye_dir, &obj_to_eye);
    // C = squared_norm(&obj_to_eye) - SQR(spr->diameter);
    C = squared_norm(&obj_to_eye) - pow(spr->diameter, 2);
    // D = SQR(B) - 4 * A * C;	
    D = pow(B, 2) - 4 * A * C;	
	return (D);
}

double	colide_cam_ray_and_sphere(t_vector cam_dir, t_coord *coords, t_objs	*objs)
{
	t_vector obj_to_eye = sub_vecs(&(coords->cam_pos), &(objs->spheres->coord));

	// printf (" %f\n", quadratic_equation(cam_dir, obj_to_eye, objs->spheres));
	if (quadratic_equation(cam_dir, obj_to_eye, objs->spheres) >= 0)
		return (1);
	else
		return (0);
}

double	colide_ray_and_objs(t_vector *cam_dir, t_coord *coords, t_objs	*objs)
{
	//colide with all objs
	// printf("%d\n", objs->spheres->is_end);
	// objs->spheres++;
	// printf("%d\n", objs->spheres->is_end);
	// exit (1);
	// t_sphere	*spheres_ini;
	// spheres_ini = objs->spheres;
	// while (objs->spheres->is_end == 0)
	// {
	// 	// print_vecs(&objs->spheres->coord);
	// 	return (colide_cam_ray_and_sphere(*cam_dir, coords, objs));
	// 	objs->spheres++;
	// }
	// objs->spheres = spheres_ini;
	int i = 0;
	while (objs->spheres[i].is_end == 0)
	{
		// print_vecs(&objs->spheres->coord);
		return (colide_cam_ray_and_sphere(*cam_dir, coords, objs));
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