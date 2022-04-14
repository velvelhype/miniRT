#include "miniRT.h"
#include <stdlib.h>

void	dummy_init_coord(t_coord *coord)
{
	coord->max_height = 400;
	coord->max_width = 400;
	coord->camera.fov = 90;
	init_vector(&coord->camera.pos, 0, 0, 0);
	init_vector(&coord->camera.orient, 0, 0, 1);
	//TODO calc the coord of the top left point in the screen.
	// cam_pos to top_left = width / tan(FOV);
	// coord->sc_bot_left = coord->cam_pos + cam_pos to top_left;
	//TODO calc the x_diff;
	//TODO calc the y_diff;
}

void	dummy_init_objs(t_objs *objs)
{
	objs->spheres = NULL;
	objs->spheres = (t_sphere *)malloc(sizeof(t_sphere) * 3);
	init_vector(&(objs->spheres)[0].coord, 1, 1, 10);
	(objs->spheres)[0].diameter = 9.8;
	init_vector(&(objs->spheres)[1].coord, -1, -1, 10);
	(objs->spheres)[1].diameter = 9.8;
	(objs->spheres)[1].is_end = 0;
	// (objs->spheres)[0].color;
	(objs->spheres)[2].is_end = 1;
	objs->planes = NULL;
	objs->cylinders = NULL;
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
	init_vector(&rt_info->light.coord, -0.0, -0.5, -0);
}
