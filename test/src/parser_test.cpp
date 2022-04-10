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
