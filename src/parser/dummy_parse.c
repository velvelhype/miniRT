#include "miniRT.h"
#include <stdlib.h>
#include "simple_operation.h"

void	dummy_init_coord(t_coord *coord)
{
	coord->max_height = 600;
	coord->max_width = 600;
	coord->cam_FOV = 90;
	init_vector(&coord->cam_pos, 0, -100, 300);
	init_vector(&coord->cam_orient, 0, 0.2, 0.9);
}

void	dummy_init_objs(t_objs *objs)
{
	objs->spheres = NULL;
	objs->spheres = (t_sphere *)malloc(sizeof(t_sphere) * 10);
	init_vector(&(objs->spheres)[0].coord, 0, 40, 600);
	(objs->spheres)[0].diameter = 100.4;
	(objs->spheres)[0].is_end = 1;
	(objs->spheres)[0].color = 0xFFFF00;
	init_vector(&(objs->spheres)[1].coord, -0.9, -0, 5);
	(objs->spheres)[1].diameter = 1;
	(objs->spheres)[1].is_end = 1;
	init_vector(&(objs->spheres)[2].coord, 0.5, 0.4, -5);
	(objs->spheres)[2].diameter = 0.4;
	(objs->spheres)[2].is_end = 0;
	init_vector(&(objs->spheres)[3].coord, -1, -1.0, -2);
	(objs->spheres)[3].diameter = 0.3;
	(objs->spheres)[3].is_end = 0;
	init_vector(&(objs->spheres)[4].coord, -4, -0.3, 0);
	(objs->spheres)[4].diameter = 0.3;
	(objs->spheres)[4].is_end = 0;
	init_vector(&(objs->spheres)[5].coord, -1, 1.2, 40);
	(objs->spheres)[5].diameter = 1.3;
	(objs->spheres)[5].is_end = 0;
	init_vector(&(objs->spheres)[6].coord, -1, 1.0, 40);
	(objs->spheres)[6].diameter = 1.3;
	(objs->spheres)[6].is_end = 0;
	(objs->spheres)[7].is_end = 1;

	objs->planes = NULL;
	objs->planes = (t_plane *)malloc(sizeof(t_plane) * 10);
	init_vector(&(objs->planes)[0].coord, 0, -10, 600);
	init_vector(&(objs->planes)[0].orient, 0, 1, 0);
	(objs->planes)[0].color = 0xFF00FF;
	(objs->planes)[0].is_end = 1;
	(objs->planes)[1].is_end = true;

	objs->cylinders = NULL;
	objs->cylinders = NULL;
	objs->cylinders = (t_cylinder *)malloc(sizeof(t_cylinder) * 10);
	init_vector(&(objs->cylinders)[0].coord, -400, 0, 2000);
	init_vector(&(objs->cylinders)[0].orient, 1, 0, 0);
	(objs->cylinders)[0].diameter = 100.1;
	(objs->cylinders)[0].height = 1000;
	(objs->cylinders)[0].color = 0x00FF00;
	(objs->cylinders)[0].is_end = 0;
	init_vector(&(objs->cylinders)[1].coord, 1, 0, 5);
	init_vector(&(objs->cylinders)[1].orient, 1, 0, 0);
	(objs->cylinders)[1].diameter = 0.1;
	(objs->cylinders)[1].height = 1;
	(objs->cylinders)[1].is_end = 1;
	init_vector(&(objs->cylinders)[2].coord, -1, 0, 5);
	init_vector(&(objs->cylinders)[2].orient, 1, 0, 0);
	(objs->cylinders)[2].diameter = 0.1;
	(objs->cylinders)[2].height = 1;
	(objs->cylinders)[2].is_end = 0;
	init_vector(&(objs->cylinders)[3].coord, -2, 0, 5);
	init_vector(&(objs->cylinders)[3].orient, 1, 0, 0);
	(objs->cylinders)[3].diameter = 0.1;
	(objs->cylinders)[3].height = 1;
	(objs->cylinders)[3].is_end = 0;
	init_vector(&(objs->cylinders)[4].coord, 2, 0, 5);
	init_vector(&(objs->cylinders)[4].orient, 1, 0, 0);
	(objs->cylinders)[4].diameter = 0.1;
	(objs->cylinders)[4].height = 1;
	(objs->cylinders)[4].is_end = 0;
	init_vector(&(objs->cylinders)[5].coord, -3, 0, 5);
	init_vector(&(objs->cylinders)[5].orient, 1, 0, 0);
	(objs->cylinders)[5].diameter = 0.1;
	(objs->cylinders)[5].height = 1;
	(objs->cylinders)[5].is_end = 0;
	init_vector(&(objs->cylinders)[6].coord, 3, 0, 5);
	init_vector(&(objs->cylinders)[6].orient, 1, 0, 0);
	(objs->cylinders)[6].diameter = 0.1;
	(objs->cylinders)[6].height = 1;
	(objs->cylinders)[6].is_end = 0;
	
	(objs->cylinders)[7].is_end = true;
}

void	dummy_init_light(t_light	*light)
{
	init_vector(&light->coord,  100, -100, 300);

	light->amb_br  = 0.5;
	light->amb_color = 0xFF;

	light->dif_br = 0.3;
	light->dif_color = 0xFFFFFF;

	light->spe_br = 0.5;
	light->spe_color = 0xFFFFFF;
}

void	dummy_parse(t_rt *rt_info)
{
	printf("dummy_parse\n");
	dummy_init_coord(&rt_info->coords);
	dummy_init_objs(&rt_info->objs);
	dummy_init_light(&rt_info->light);
}