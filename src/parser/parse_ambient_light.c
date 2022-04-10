#include "parser.h"

// <Identifier> <ratio> <R>,<G>,<B>
void	parse_ambient_light(t_rt *rt_info, char **tokens)
{
	size_t	i;

	i = 0;
	if (tokens[1] == NULL || tokens[2] == NULL || tokens[3] != NULL)
		custom_exit("Ambient light: invalid number of arguments");
	rt_info->ambient.br_ratio = parse_ratio(tokens[1]);
	rt_info->ambient.color = parse_color(tokens[2]);
}
