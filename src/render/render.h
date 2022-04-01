#ifndef RENDER_H
# define RENDER_H

#include "miniRT.h"

typedef struct s_front_point
{
	double		length;
	t_vector	coord;
	t_vector	reflec_dir;
} t_front_point;

void	render(t_rt *rt_info);
int	detect_reflection(t_rt *rt_info, int x, int y);
t_front_point	colide_ray_and_objs(t_vector *cam_dir, t_coord *coords, t_objs *objs);

#endif