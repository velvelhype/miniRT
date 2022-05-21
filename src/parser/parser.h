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

typedef enum e_uniq_obj
{
	AMBIENT = 0,
	CAMERA = 1,
	LIGHT = 2
}			t_uniq_obj;

# define UNIQUE_OBJ_SIZE 3

char		*get_next_line(int fd);
void		dummy_parse(t_rt *rt_info);
void		parse(char *filename, t_rt *rt_info);
void		parse_line(t_rt *rt_info, char *line, bool *used);
void		parse_ambient_light(t_rt *rt_info, char **tokens, bool is_used);
void		custom_exit(char *msg);
double		parse_ratio(char *ratio);
void		ft_split_free(char **tokens);
t_color		parse_color(char *vec3_str);
t_vector	parse_vector3(char *vec3_str);
t_vector	parse_normarized_vector3(char *vec3_str);
t_vector	parse_coordinate(char *vec3_str);
void		parse_camera(t_rt *rt_info, char **tokens, bool is_used);
void		parse_light(t_rt *rt_info, char **tokens, bool is_used);
void		parse_sphere(t_rt *rt_info, char **tokens);
void		parse_plane(t_rt *rt_info, char **tokens);
void		parse_cylinder(t_rt *rt_info, char **tokens);
void		parse_objs(t_rt *rt_info, char **tokens, t_obj_type type);
t_sphere	*init_sphere(t_sphere sphere);
t_plane		*init_plane(t_plane plane);
t_cylinder	*init_cylinder(t_cylinder cylinder);
int			file_open(char *filename);

#endif
