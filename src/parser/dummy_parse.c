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
	objs->spheres = (t_sphere *)malloc(sizeof(t_sphere) * 2);
	init_vector(&(objs->spheres)[0].coord, 0, 0, 10);
	(objs->spheres)[0].diameter = 9;
	// (objs->spheres)[0].color;
	(objs->spheres)[1].is_end = 1;
	objs->planes = NULL;
	objs->cylinders = NULL;
}

void	dummy_parse(t_rt *rt_info)
{
	printf("dummy_parse\n");
	dummy_init_coord(&rt_info->coords);
	dummy_init_objs(&rt_info->objs);
}