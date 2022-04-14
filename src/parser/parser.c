#include "parser.h"

void	init_used_flags(bool *used)
{
	used[AMBIENT] = false;
	used[CAMERA] = false;
	used[LIGHT] = false;
}

bool	is_all_used(bool *used)
{
	return (used[AMBIENT] && used[CAMERA] && used[LIGHT]);
}

void	parse(char *filename, t_rt *rt_info)
{
	int		fd;
	char	*line;
	char	*trimmed_line;
	bool	used[UNIQUE_OBJ_SIZE];

	init_used_flags(used);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		trimmed_line = ft_strtrim(line, " \t\n\r");
		free(line);
		parse_line(rt_info, trimmed_line, used);
		free(trimmed_line);
		line = get_next_line(fd);
	}
	if (!is_all_used(used))
		custom_exit("Camera, Light, Ambient light are required");
}

void	parse_line(t_rt *rt_info, char *line, bool *used)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (ft_streq(tokens[0], "A"))
	{
		parse_ambient_light(rt_info, tokens, used[AMBIENT]);
		used[AMBIENT] = true;
	}
	else if (ft_streq(tokens[0], "C"))
	{
		parse_camera(rt_info, tokens, used[CAMERA]);
		used[CAMERA] = true;
	}
	else if (ft_streq(tokens[0], "L"))
	{
		parse_light(rt_info, tokens, used[LIGHT]);
		used[LIGHT] = true;
	}
	else if (ft_streq(tokens[0], "sp"))
		parse_objs(rt_info, tokens, SPHERE);
	else if (ft_streq(tokens[0], "pl"))
		parse_objs(rt_info, tokens, PLANE);
	else if (ft_streq(tokens[0], "cy"))
		parse_objs(rt_info, tokens, CYLINDER);
	ft_split_free(tokens);
}

void	ft_split_free(char **tokens)
{
	size_t	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
