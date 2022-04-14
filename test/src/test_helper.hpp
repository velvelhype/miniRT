#ifndef TEST_HELPER_H
#define TEST_HELPER_H
#include <gtest/gtest.h>
extern "C"
{
#include "libft.h"
#include "parser.h"
}

extern const int NO_MEAN;
typedef std::vector<double> test_t_vec;
typedef std::vector<int> test_t_color;

// br_ratio, color
typedef std::tuple<double, test_t_color> test_t_ambient;
// pos, orient, fov
typedef std::tuple<test_t_vec, test_t_vec, int> test_t_camera;
// coord, br_ratio
typedef std::tuple<test_t_vec, double> test_t_light;
// coord, diameter, color
typedef std::tuple<test_t_vec, double, test_t_color> test_t_sphere;
// coord, orient, color
typedef std::tuple<test_t_vec, test_t_vec, test_t_color> test_t_plane;
// coord, orient, diameter, height, color
typedef std::tuple<test_t_vec, test_t_vec,double, double, test_t_color> test_t_cylinder;
// type, coord, orient, diameter, height, color
typedef std::tuple<t_obj_type, test_t_vec, test_t_vec, double, double, test_t_color> test_t_obj;

typedef std::vector<test_t_obj> test_t_objs;

void check_color(t_color color, test_t_color vec);
void check_ratio(double ratio, double expected);
void check_ambient_light(t_rt *rt_info, test_t_ambient ambient_tuple);
void check_camera(t_rt *rt_info, test_t_camera camera_tuple);
void check_light(t_rt *rt_info, test_t_light light_tuple);
void check_obj(void *obj_elm, test_t_obj obj);
void check_objs(t_list *objs_lst, test_t_objs objs);
void check_rt(t_rt *rt_info, test_t_objs objs, test_t_ambient ambient_tuple, test_t_camera camera_tuple, test_t_light light_tuple);

#endif
