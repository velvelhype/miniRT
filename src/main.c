#include "miniRT.h"
#include "parser.h"
#include "render.h"

int	main(int argc, char **argv)
{
	t_rt	rt_info;

	rt_info.objs = NULL;
	printf("start\n");
	if (argc != 2)
		custom_exit("Invalid number of arguments");
	parse(argv[1], &rt_info);
	render(&rt_info, &rt_info.mlx_config);
}
