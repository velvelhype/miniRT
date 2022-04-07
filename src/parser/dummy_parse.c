#include "miniRT.h"
#include <stdlib.h>

void	dummy_init_coord(t_coord *coord)
{
	coord->max_height = 400;
	coord->max_width = 400;
	coord->cam_FOV = 90;
	init_vector(&coord->cam_pos, 0, 0, 0);
	init_vector(&coord->cam_orient, 0, 0, 1);
	//TODO calc the coord of the top left point in the screen.
	// cam_pos to top_left = width / tan(FOV);
	// coord->sc_bot_left = coord->cam_pos + cam_pos to top_left;
	//TODO calc the x_diff;
	//TODO calc the y_diff;
}

void	dummy_init_objs(t_objs *objs)
{
	objs->spheres = NULL;
	objs->spheres = (t_sphere *)malloc(sizeof(t_sphere) * 10);
	init_vector(&(objs->spheres)[0].coord, 0.1, 0.1, 10);
	(objs->spheres)[0].diameter = 9.8;
	(objs->spheres)[0].is_end = 0;
	init_vector(&(objs->spheres)[1].coord, -1, 0.7, 10);
	(objs->spheres)[1].diameter = 9.7;
	(objs->spheres)[1].is_end = 0;
	init_vector(&(objs->spheres)[2].coord, 1, 0.7, 10);
	(objs->spheres)[2].diameter = 9;
	(objs->spheres)[2].is_end = 0;
	init_vector(&(objs->spheres)[3].coord, -1, 0.7, 10);
	(objs->spheres)[3].diameter = 9.2;
	(objs->spheres)[3].is_end = 1;
	(objs->spheres)[4].is_end = 1;

	objs->planes = NULL;
	objs->planes = (t_plane *)malloc(sizeof(t_plane) * 10);
	init_vector(&(objs->planes)[0].coord, 0, 1, 0.26);
	init_vector(&(objs->planes)[0].orient, 0, 0.2, 0.7);
	(objs->planes)[0].is_end = 0;
	(objs->planes)[1].is_end = true;

	objs->cylinders = NULL;
	objs->cylinders = NULL;
	objs->cylinders = (t_cylinder *)malloc(sizeof(t_cylinder) * 10);
	init_vector(&(objs->cylinders)[0].coord, 0.1, 0, 10);
	init_vector(&(objs->cylinders)[0].orient, 1, 0, 0);
	(objs->cylinders)[0].diameter = 9;
	(objs->cylinders)[0].height = 2;
	(objs->cylinders)[0].is_end = false;
	(objs->cylinders)[1].is_end = true;
}

// void	dummy_init_lights(t_lights *lights)
// {
// 	lights = (t_lights *)malloc(sizeof(t_lights) * 2);
// 	init_vector(&(lights[0]).coord, 0, 0, -100);
// 	lights[0].br_ratio = 1;
// 	lights[1].is_end = TRUE;
// 	// print_vecs(&lights[0].coord);
// }

void	dummy_parse(t_rt *rt_info)
{
	printf("dummy_parse\n");
	dummy_init_coord(&rt_info->coords);
	dummy_init_objs(&rt_info->objs);
	// dummy_init_lights(rt_info->lights);
	rt_info->lights = (t_lights *)malloc(sizeof(t_lights) * 2);
	init_vector(&rt_info->lights[0].coord, -0.2, -0.0, -0);
}