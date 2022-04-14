#include "parser.h"

t_plane	*init_plane(t_plane plane)
{
	t_plane	*res;

	res = (t_plane *)ft_calloc(sizeof(t_plane), 1);
	res->type = plane.type;
	res->coord = plane.coord;
	res->orient = plane.orient;
	res->color = plane.color;
	return (res);
}
