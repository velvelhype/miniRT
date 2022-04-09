#ifndef PARSER_H
# define PARSER_H
# define FD_SIZE 65536
# define BUFFER_SIZE 4096
# include "miniRT.h"
# include <errno.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
char	*get_next_line(int fd);
void	dummy_parse(t_rt *rt_info);

#endif
