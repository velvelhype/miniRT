#ifndef RENDER_H
# define RENDER_H
# include "miniRT.h"

typedef struct s_front_point
{
	double		length;
	t_color		color;
	t_vector	coord;
	t_vector	reflec_dir;
	t_vector	cam_dir;
}	t_front_point;

typedef struct s_cylinder_discriminant
{
	double		a;
	double		b;
	double		c;
	double		d;
	t_vector	s;
	t_vector	x;
}	t_cyl_dis;

typedef struct s_cylinder_stat
{
	t_vector	ray;
	t_vector	cam;
	double		t_outer;
	double		t_inner;
	t_vector	p_outer;
	t_vector	p_inner;
	t_vector	center2p_outer;
	t_vector	center2p_inner;
	double		y_out;
	double		y_in;
}	t_cyl_stat;

void			render(t_rt *rt_info, t_mlx *mlx_config);
t_color			detect_reflection(t_rt *rt_info, int x, int y);
void			my_pixel_put(t_mlx *mlx_info, int x, int y, t_color color);
void			init_col(t_color *color, int r, int g, int b);
void			init_lum(t_luminance *lum, double r, double g, double b);
void			make_lum(t_luminance *lum, t_color *color, double ratio);
t_color			make_light_from_lum(t_luminance lum);
double			spec_ref(t_vector l, double d, t_vector r, t_front_point i);
t_front_point	colide_ray_and_objs(t_vector *r, t_vector *c, t_list *objs);
t_front_point	colide_cam_ray_and_sphere(t_vector r, t_vector *c, t_sphere *s);
t_front_point	colide_cam_ray_and_plane(t_vector r, t_vector *c, t_plane *p);
t_front_point	colide_ray_and_cyl(t_vector *r, t_vector *c, t_cylinder *cy);
bool			is_in_shadow(t_rt *rt_info, t_front_point *i, t_list *objs);

#endif
