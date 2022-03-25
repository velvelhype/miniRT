# ifndef MINIRT_H
# define MINIRT_H

typedef struct s_rt
{
	int		max_width;
	int		max_height;
	int		is_threeD;
	float	rotation;
	void	*mlx_ptr;
	void	*win_ptr;

	void	*image;
	char	*addr;
	int		pix_bits;
	int		line_len;
	int		endi;

	double	lean_x;
	double	lean_y;
	int		shift_x;
	int		shift_y;
	int		zoom;
} t_rt;

#include <stdio.h>

#endif