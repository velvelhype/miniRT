#include "test_helper.hpp"

void check_ambient_light(t_rt *rt_info, test_t_ambient ambient_tuple)
{
	t_lights ambient = rt_info->ambient;

	check_ratio(ambient.br_ratio, std::get<0>(ambient_tuple));
	check_color(ambient.color, std::get<1>(ambient_tuple));
}

void check_ratio(double ratio, double expected)
{
	EXPECT_DOUBLE_EQ(ratio, expected);
}

void check_color(t_color color, test_t_color vec)
{
	EXPECT_EQ(color.red, vec[0]);
	EXPECT_EQ(color.green, vec[1]);
	EXPECT_EQ(color.blue, vec[2]);
}
