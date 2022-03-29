#include "render.h"
#include <stdlib.h>

double	colide_cam_ray_and_sphere(t_coord *coords, t_vector cam_dir)
{
	printf("let's role\n");
	return (0);
}

double	colide_ray_and_objs(t_vector *cam_dir, t_coord *coords, t_objs	*objs)
{
	//colide with all objs
	// printf("%d\n", objs->spheres->is_end);
	// objs->spheres++;
	// printf("%d\n", objs->spheres->is_end);
	// exit (1);
	int i = 0;
	while (objs->spheres[i].is_end == 0)
	{
		print_vecs(&objs->spheres->coord);
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