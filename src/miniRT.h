# ifndef MINIRT_H
# define MINIRT_H

#include <stdio.h>
#include "vector.h"
#include <stdbool.h>

typedef	struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image;
	char	*addr;
	int		pix_bits;
	int		line_len;
	int		endi;
} t_mlx;

typedef struct s_coord
{
	int			max_width;
	int			max_height;
	//TODO make camera structure
	int			cam_FOV;
	t_vector	cam_pos;
	t_vector	cam_orient;
	t_vector	sc_bot_left;
	t_vector	sc_diff_x;
	t_vector	sc_diff_y;
} t_coord;

typedef struct s_color
{
	int red;
	int green;
	int blue;
} t_color;

typedef struct s_sphere
{
	bool		is_end;
	t_vector	coord;
	double		diameter;
	t_color		color;
} t_sphere;

typedef struct s_plane
{
	bool		is_end;
	t_vector	coord;
	t_vector	orient;
	t_color		color;
} t_plane;

typedef struct s_cylinder
{
	bool		is_end;
	t_vector	coord;
	t_vector	orient;
	double		diameter;
	double		height;
	t_color 	color;
} t_cylinder;

typedef struct s_objs
{
	t_sphere *spheres;
	t_plane *planes;
	t_cylinder *cylinders;
} t_objs;

typedef struct s_rt
{
	t_coord coords;
	t_mlx	mlx_config;
	t_objs	objs;
	//t_objs objs
	//t_light lights
} t_rt;

#endif