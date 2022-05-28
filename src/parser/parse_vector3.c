#include "parser.h"
#include <float.h>
#include <math.h>

t_vector	parse_vector3(char *vec3_str)
{
	t_vector	result;
	char		**tokens;
	bool		flag;

	flag = true;
	tokens = ft_split(vec3_str, ',');
	if (tokens[0] == NULL || tokens[1] == NULL || tokens[2] == NULL
		|| tokens[3] != NULL)
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

t_vector	parse_normarized_vector3(char *vec3_str)
{
	t_vector	result;
	double		norm2;

	result = parse_vector3(vec3_str);
	norm2 = result.x * result.x + result.y * result.y + result.z * result.z;
	if (fabs(norm2 - 1) > 0.1)
		custom_exit("Vector3: input is not normarized");
	result.x /= norm2;
	result.y /= norm2;
	result.z /= norm2;
	return (result);
}
