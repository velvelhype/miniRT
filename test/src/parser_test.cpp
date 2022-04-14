#include "test_helper.hpp"
#include <algorithm>
#include <fcntl.h>
#include <gtest/gtest.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>

extern "C"
{
#include "libft.h"
#include "parser.h"
}

const int NO_MEAN = 123;
TEST(ParseLine_Ambient, success)
{
	char line[] = "A 0.2 255,255,255";

	t_rt rt_info;
	parse_line(&rt_info, line);
	test_t_ambient expect = std::make_tuple(0.2, test_t_color({255, 255, 255}));
	check_ambient_light(&rt_info, expect);
}

TEST(ParseLine_Camera, success)
{
	char line[] = "C -50.0,0,20 0,0,1 70";

	t_rt rt_info;
	parse_line(&rt_info, line);
	test_t_camera expect =
		std::make_tuple(test_t_vec({-50.0, 0, 20}), test_t_vec({0, 0, 1}), 70);
	check_camera(&rt_info, expect);
}

TEST(ParseLine_Camera, success2)
{
	char line[] = "C -53.1,0.0,123 0,0,-1.0 70";

	t_rt rt_info;
	parse_line(&rt_info, line);
	test_t_camera expect = std::make_tuple(
		test_t_vec({-53.1, 0.0, 123}), test_t_vec({0, 0, -1.0}), 70);
	check_camera(&rt_info, expect);
}

TEST(ParseLine_Light, success)
{
	char line[] = "L -40.0,50.0,0.0 0.6 ";

	t_rt rt_info;
	parse_line(&rt_info, line);
	test_t_light expect = std::make_tuple(test_t_vec({-40.0, 50.0, 0.0}), 0.6);
	check_light(&rt_info, expect);
}

// type, coord, orient, diameter, height, color
// -> coord, diameter, color
TEST(ParseLine_Sphere, success)
{
	char line[] = "sp 0.0,0.0,20.6 12.6 10,0,255";

	t_rt rt_info;
	rt_info.objs = NULL;
	parse_line(&rt_info, line);
	test_t_objs expect = {{SPHERE,
						   {0.0, 0.0, 20.6},
						   {},
						   12.6,
						   NO_MEAN,
						   {10, 0, 255}}};


	check_objs(rt_info.objs, expect);
	ft_lstclear(&rt_info.objs, &free);
}

// type, coord, orient, diameter, height, color
// -> coord, orient, color
TEST(ParseLine_Plane, success)
{
	char line[] = "pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225";

	t_rt rt_info;
	rt_info.objs = NULL;
	parse_line(&rt_info, line);
	test_t_objs expect = {{PLANE,
						   {0.0, 0.0, -10.0},
						   {0, 1, 0},
						   NO_MEAN,
						  	NO_MEAN,
						   {0, 0, 225}}};
	check_objs(rt_info.objs, expect);
	ft_lstclear(&rt_info.objs, &free);
}

// type, coord, orient, diameter, height, color
// -> coord, orient, color
TEST(ParseLine_Cylinder, success)
{
	char line[] = "cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255";

	t_rt rt_info;
	rt_info.objs = NULL;
	parse_line(&rt_info, line);
	test_t_objs expect = {{CYLINDER,
						   {50.0, 0.0, 20.6},
						   {0, 0, 1.0},
						   14.2,
						  	21.42,
						   {10, 0, 255}}};
	check_objs(rt_info.objs, expect);
	ft_lstclear(&rt_info.objs, &free);
}

TEST(Parse, none)
{
	char line[] = "cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255";

	t_rt rt_info;
	rt_info.objs = NULL;
	parse_line(&rt_info, line);
	test_t_objs expect = {{CYLINDER,
						   {50.0, 0.0, 20.6},
						   {0, 0, 1.0},
						   14.2,
						  	21.42,
						   {10, 0, 255}}};
	check_objs(rt_info.objs, expect);
	ft_lstclear(&rt_info.objs, &free);
}
