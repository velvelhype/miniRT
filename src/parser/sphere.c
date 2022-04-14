#include "parser.h"

t_sphere	*init_sphere(t_sphere sphere)
{
	t_sphere	*res;

	res = (t_sphere *)ft_calloc(sizeof(t_sphere), 1);
	res->type = sphere.type;
	res->coord = sphere.coord;
	res->diameter = sphere.diameter;
	res->color = sphere.color;
	return (res);
}
