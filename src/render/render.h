#ifndef RENDER_H
# define RENDER_H

#include "miniRT.h"

void	render(t_rt *rt_info);
double	detect_colision(t_rt *rt_info, int x, int y);
double	colide_ray_and_objs(t_vector *cam_dir, t_coord *coords, t_objs *objs);

#endif