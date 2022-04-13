#include "test_helper.hpp"

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

void check_vector(t_vector coords, test_t_vec vec)
{
	EXPECT_DOUBLE_EQ(coords.x, vec[0]);
	EXPECT_DOUBLE_EQ(coords.y, vec[1]);
	EXPECT_DOUBLE_EQ(coords.z, vec[2]);
}

void check_ambient_light(t_rt *rt_info, test_t_ambient ambient_tuple)
{
	t_light ambient = rt_info->ambient;

	check_ratio(ambient.br_ratio, std::get<0>(ambient_tuple));
	check_color(ambient.color, std::get<1>(ambient_tuple));
}

void check_camera(t_rt *rt_info, test_t_camera camera_tuple)
{
	t_camera camera = rt_info->coords.camera;

	check_vector(camera.pos, std::get<0>(camera_tuple));
	check_vector(camera.orient, std::get<1>(camera_tuple));
	EXPECT_EQ(camera.fov, std::get<2>(camera_tuple));
}

void check_light(t_rt *rt_info, test_t_light light_tuple)
{
	t_light light = rt_info->light;

	check_vector(light.coord, std::get<0>(light_tuple));
	check_ratio(light.br_ratio, std::get<1>(light_tuple));
}
