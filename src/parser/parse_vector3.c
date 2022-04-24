#include "parser.h"
#include <float.h>

t_vector	parse_vector3(char *vec3_str)
{
	t_vector	result;
	char		**tokens;
	bool		flag;

	flag = true;
	tokens = ft_split(vec3_str, ',');
	if (tokens[0] == NULL || tokens[1] == NULL || tokens[2] == NULL || tokens[3] != NULL)
		custom_exit("Vector3: invalid number of arguments");
	result.x = ft_my_atof(tokens[0], &flag);
	if (!flag)
		custom_exit("Vector3: invalid x value");
	result.y = ft_my_atof(tokens[1], &flag);
	if (!flag)
		custom_exit("Vector3: invalid y value");
	result.z = ft_my_atof(tokens[2], &flag);
	if (!flag)
		custom_exit("Vector3: invalid z value");
	ft_split_free(tokens);
	return (result);
}

t_color	parse_color(char *vec3_str)
{
	t_color	result;
	char	**tokens;

	tokens = ft_split(vec3_str, ',');
	if (tokens[0] == NULL || tokens[1] == NULL || tokens[2] == NULL || tokens[3] != NULL)
		custom_exit("Vector3: invalid number of arguments");
	result.red = ft_atoi(tokens[0]);
	result.green = ft_atoi(tokens[1]);
	result.blue = ft_atoi(tokens[2]);
	if (result.red < 0 || result.red > 255 || result.green < 0 || result.green > 255 || result.blue < 0 || result.blue > 255)
		custom_exit("Color: invalid color");
	ft_split_free(tokens);
	return (result);
}
