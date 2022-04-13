#include <algorithm>
#include <fcntl.h>
#include <gtest/gtest.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include "test_helper.hpp"
#include <gtest/gtest.h>

extern "C"
{
#include "libft.h"
#include "parser.h"
}


TEST(ParseLine_Ambient, success)
{
	char *line = "A 0.2 255,255,255";

	t_rt rt_info;
	parse_line(&rt_info, line);
	test_t_ambient expect = std::make_tuple(0.2, test_t_color({255, 255, 255}));
	check_ambient_light(&rt_info, expect);
}

TEST(ParseLine_Camera, success)
{
	char *line = "C -50.0,0,20 0,0,1 70";

	t_rt rt_info;
	parse_line(&rt_info, line);
	test_t_camera expect = std::make_tuple(test_t_vec({-50.0, 0, 20}), test_t_vec({0, 0, 1}), 70);
	check_camera(&rt_info, expect);
}

TEST(ParseLine_Camera, success2)
{
	char *line = "C -53.1,0.0,123 0,0,-1.0 70";

	t_rt rt_info;
	parse_line(&rt_info, line);
	test_t_camera expect = std::make_tuple(test_t_vec({-53.1, 0.0, 123}), test_t_vec({0, 0, -1.0}), 70);
	check_camera(&rt_info, expect);
}


TEST(ParseLine_Light, success)
{
	char *line = "L -40.0,50.0,0.0 0.6 ";

	t_rt rt_info;
	parse_line(&rt_info, line);
	test_t_light expect = std::make_tuple(test_t_vec({-40.0, 50.0, 0.0}), 0.6);
	check_light(&rt_info, expect);
}


