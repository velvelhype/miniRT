# ifndef MINIRT_H
# define MINIRT_H

#include <stdio.h>
#include "vector.h"

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
	int			FOV;
	t_vector	cam_pos;
	t_vector	cam_orient;
} t_coord;

typedef struct s_rt
{
	t_coord coords;
	t_mlx	mlx_config;
	//t_objs objs
	//t_light lights
} t_rt;

#endif