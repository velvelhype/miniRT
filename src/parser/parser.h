#ifndef PARSER_H
# define PARSER_H
# define FD_SIZE 1024
# define BUFFER_SIZE 4096
# include "libft.h"
# include "miniRT.h"
# include "vector.h"
# include <errno.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char		*get_next_line(int fd);
void		dummy_parse(t_rt *rt_info);
void		parse(char *filename, t_rt *rt_info);
void		parse_line(t_rt *rt_info, char *line);
void		parse_ambient_light(t_rt *rt_info, char **tokens);
void		custom_exit(char *msg);
double		parse_ratio(char *ratio);
void		ft_split_free(char **tokens);
t_color		parse_color(char *vec3_str);
t_vector	parse_vector3(char *vec3_str);
t_vector	parse_coordinate(char *vec3_str);
void		parse_camera(t_rt *rt_info, char **tokens);
void		parse_light(t_rt *rt_info, char **tokens);

#endif
