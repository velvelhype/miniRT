#include "parser.h"

// <Identifier> <x>,<y>,<z> <camera-x>,<camera-y>,<camera-z> <FOV>
void	parse_camera(t_rt *rt_info, char **tokens)
{
	t_camera	*cam;

	cam = &rt_info->coords.camera;
	if (tokens[1] == NULL || tokens[2] == NULL || tokens[3] == NULL || tokens[4] != NULL)
		custom_exit("Ambient light: invalid number of arguments");
	cam->pos = parse_vector3(tokens[1]);
	cam->orient = parse_vector3(tokens[2]);
	cam->fov = ft_atoi(tokens[3]);
}
