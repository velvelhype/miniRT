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

void check_color(t_color color, test_t_color vec);
void check_ratio(double ratio, double expected);
void check_ambient_light(t_rt *rt_info, test_t_ambient ambient_tuple);

#endif
