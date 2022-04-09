#include "miniRT.h"
#include "render.h"
#include "parser.h"

int main(int argc, char **argv)
{
	printf("start\n");
	t_rt	rt_info;

	//	if (argc != 3)
	//		error_exit();
	//	parse_rt_file(argv, &rt_info);
	dummy_parse(&rt_info);
	//	check_parsed_info(&rt_info);
	render(&rt_info);
}
