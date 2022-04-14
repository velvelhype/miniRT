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

// coord, diameter, color
static void check_sphere(void *sphere_elm, test_t_sphere sphere_tuple)
{
	t_sphere *sphere = (t_sphere *)sphere_elm;

	check_vector(sphere->coord, std::get<0>(sphere_tuple));
	EXPECT_DOUBLE_EQ(sphere->diameter, std::get<1>(sphere_tuple));
	check_color(sphere->color, std::get<2>(sphere_tuple));
}

// coord, orient, color
static void check_plane(t_plane *plane, test_t_plane plane_tuple)
{
	check_vector(plane->coord, std::get<0>(plane_tuple));
	check_vector(plane->orient, std::get<1>(plane_tuple));
	check_color(plane->color, std::get<2>(plane_tuple));
}

// coord, orient, diameter, height, color
static void check_cylinder(t_cylinder *cylinder, test_t_cylinder cylinder_tuple)
{
	check_vector(cylinder->coord, std::get<0>(cylinder_tuple));
	check_vector(cylinder->orient, std::get<1>(cylinder_tuple));
	EXPECT_DOUBLE_EQ(cylinder->diameter, std::get<2>(cylinder_tuple));
	EXPECT_DOUBLE_EQ(cylinder->height, std::get<3>(cylinder_tuple));
	check_color(cylinder->color, std::get<4>(cylinder_tuple));
}

// type, coord, orient, diameter, height, color
void check_obj(void *obj_elm, test_t_obj obj)
{
	t_obj_type type = std::get<0>(obj);

	if (type == SPHERE)
	{
		// coord, diameter, color
		test_t_sphere sphere_tuple = std::make_tuple(std::get<1>(obj), std::get<3>(obj), std::get<5>(obj));
		t_sphere *sphere = (t_sphere *)obj_elm;
		ASSERT_NE(sphere, nullptr);
		EXPECT_EQ(sphere->type, type);
		check_sphere(sphere, sphere_tuple);
	} else if (type == PLANE)
	{
		test_t_plane plane_tuple = std::make_tuple(std::get<1>(obj), std::get<2>(obj), std::get<5>(obj));
		t_plane *plane = (t_plane *)obj_elm;
		ASSERT_NE(plane, nullptr);
		EXPECT_EQ(plane->type, type);
		check_plane(plane, plane_tuple);
	} else if (type == CYLINDER)
	{
		test_t_cylinder cylinder_tuple = std::make_tuple(std::get<1>(obj), std::get<2>(obj), std::get<3>(obj), std::get<4>(obj), std::get<5>(obj));
		t_cylinder *cylinder = (t_cylinder *)obj_elm;
		ASSERT_NE(cylinder, nullptr);
		EXPECT_EQ(cylinder->type, type);
		check_cylinder(cylinder, cylinder_tuple);
	}
}

void check_objs(t_list *objs, test_t_objs objs_vec)
{
	void *obj;

	ASSERT_EQ(ft_lstsize(objs), objs_vec.size());
	for (auto x: objs_vec)
	{
		obj = objs->content;
		check_obj(obj, x);
		objs = objs->next;
	}
}
