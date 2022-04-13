#ifndef TEST_HELPER_H
#define TEST_HELPER_H
#include <gtest/gtest.h>
extern "C"
{
#include "libft.h"
#include "parser.h"
}



typedef std::vector<double> test_t_vec;
typedef std::vector<int> test_t_color;
typedef std::tuple<double, test_t_color> test_t_ambient;
typedef std::tuple<test_t_vec, test_t_vec, int> test_t_camera;
typedef std::tuple<test_t_vec, double> test_t_light;

void check_color(t_color color, test_t_color vec);
void check_ratio(double ratio, double expected);
void check_ambient_light(t_rt *rt_info, test_t_ambient ambient_tuple);
void check_camera(t_rt *rt_info, test_t_camera camera_tuple);
void check_light(t_rt *rt_info, test_t_light light_tuple);

#endif
