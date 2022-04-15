#ifndef RENDER_H
# define RENDER_H
# include "miniRT.h"

typedef struct s_front_point
{
	double		length;
	int			color;
	t_vector	coord;
	t_vector	reflec_dir;
	t_vector	cam_dir;
}	t_front_point;

void			render(t_rt *rt_info);
int				detect_reflection(t_rt *rt_info, int x, int y);

int				ambient_light(t_light *light, t_front_point *intersection);
int				diffuse_and_specular_reflection(t_vector *cam_dir, t_light *light, t_front_point *intersection);
int				make_light_color(int color, double br, int pt_color);

t_front_point	colide_ray_and_objs(t_vector *cam_dir, t_vector *cam_pos, t_objs *objs);
double			sphere_discriminant(t_vector eye_dir, t_vector obj_to_eye, t_sphere *spr);
t_front_point	colide_cam_ray_and_sphere(t_vector cam_dir, t_vector *cam_pos, t_sphere *sphere);
t_front_point	colide_cam_ray_and_plane(t_vector cam_dir, t_vector *cam_pos, t_plane *plane);
t_front_point	colide_cam_ray_and_cylinder(t_vector cam_dir, t_vector *cam_pos, t_cylinder *cylinder);
bool			colide_shadow_ray_and_objs(t_vector *cam_dir, t_vector *cam_pos, t_objs *objs);
bool			is_in_shadow(t_vector *cam_dir, t_vector *cam_pos, t_objs	*objs, double max_len);

#endif