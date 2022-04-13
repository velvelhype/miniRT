#include "parser.h"

void	parse(char *filename, t_rt *rt_info)
{
	int		fd;
	char	*line;
	char	*trimmed_line;

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
		parse_line(rt_info, trimmed_line);
		free(trimmed_line);
		line = get_next_line(fd);
	}
}

void	parse_line(t_rt *rt_info, char *line)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (ft_streq(tokens[0], "A"))
		parse_ambient_light(rt_info, tokens);
	else if (ft_streq(tokens[0], "C"))
		parse_camera(rt_info, tokens);
	else if (ft_streq(tokens[0], "L"))
		parse_light(rt_info, tokens);
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
