#include "parser.h"
#include <errno.h>

void	custom_exit(char *msg)
{
	if (errno != 0)
		perror("Error\n");
	else
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd(msg, STDERR);
	}
	exit(EXIT_FAILURE);
}
