#ifndef MINIRT_H
#define MINIRT_H

#define EPSILON_F 0.001
#define TRUE 1
#define FALSE 0
# define SHININESS 4

#include "libft.h"
#include "vector.h"
#include <stdbool.h>
#include <stdio.h>

typedef enum e_stdio
{
	STDIN = 0,
	STDIOUT = 1,
	STDERR = 2
} t_stdio;

typedef struct s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
	void *image;
	char *addr;
	int pix_bits;
	int line_len;
	int endi;
} t_mlx;

typedef struct s_camera
{
	t_vector pos;
	t_vector orient;
	int fov;
} t_camera;

typedef struct s_coord
{
	int			max_width;
	int			max_height;
	t_camera	camera;
	t_vector	sc_bot_left;
	t_vector	sc_diff_x;
	t_vector	sc_diff_y;
}	t_coord;


typedef struct s_color
{
	int red;
	int green;
	int blue;
} t_color;

typedef enum e_obj_type
{
	SPHERE = 0,
	PLANE = 1,
	CYLINDER = 2,
} t_obj_type;

typedef struct s_obj
{
	t_obj_type type;
} t_obj;

typedef struct s_sphere
{
	t_obj_type type;
	t_vector coord;
	double diameter;
	t_color color;
} t_sphere;

typedef struct s_plane
{
	t_obj_type type;
	t_vector coord;
	t_vector orient;
	t_color color;
} t_plane;

typedef struct s_cylinder
{
	t_obj_type type;
	t_vector coord;
	t_vector orient;
	double diameter;
	double height;
	t_color color;
} t_cylinder;

typedef struct s_light
{
	double br_ratio;
	t_vector coord;
	t_color color;
} t_light;

typedef struct s_rt
{
	t_coord coords;
	t_mlx mlx_config;
	t_list *objs;
	t_light light;
	t_light ambient;
} t_rt;

#endif
