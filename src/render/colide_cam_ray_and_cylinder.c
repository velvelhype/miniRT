/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colide_cam_ray_and_cylinder.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:32:50 by akito             #+#    #+#             */
/*   Updated: 2022/05/28 20:32:50 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <stdlib.h>
#include <math.h>
#include "simple_operation.h"
#include "vector.h"

// split 3 part, make 2 structs

void	cyl_discriminant(t_cyl_dis *d, t_vector *r, t_vector *c, t_cylinder *cy)
{
	t_vector	subbed;
	t_vector	c_cross;

	cross_vecs(&d->s, r, &cy->orient);
	d->a = norm(&d->s);
	d->a = square(d->a);
	cross_vecs(&d->s, r, &cy->orient);
	subbed = sub_vecs(c, &cy->coord);
	cross_vecs(&d->x, &subbed, &cy->orient);
	d->b = (double)2 * dot_vecs(&d->s, &d->x);
	subbed = sub_vecs(c, &cy->coord);
	cross_vecs(&c_cross, &subbed, &cy->orient);
	d->c = norm(&c_cross);
	d->c = square(d->c) - square(cy->diameter);
	d->d = square(d->b) - (double)4 * d->a * d->c;
}

void	make_cyl_stat(t_cyl_dis *dis, t_cyl_stat *cyl_stat, t_cylinder *cyl)
{
	t_vector	multi;

	cyl_stat->t_outer = (-dis->b - sqrt(dis->d)) / ((double)2 * dis->a);
	cyl_stat->t_inner = (-dis->b + sqrt(dis->d)) / ((double)2 * dis->a);
	multi = mult_vecs(&cyl_stat->ray, cyl_stat->t_outer);
	cyl_stat->p_outer = add_vecs(&cyl_stat->cam, &multi);
	multi = mult_vecs(&cyl_stat->ray, cyl_stat->t_inner);
	cyl_stat->p_inner = add_vecs(&cyl_stat->cam, &multi);
	cyl_stat->center2p_outer = sub_vecs(&cyl_stat->p_outer, &cyl->coord);
	cyl_stat->center2p_inner = sub_vecs(&cyl_stat->p_inner, &cyl->coord);
	cyl_stat->y_out = dot_vecs(&cyl_stat->center2p_outer, &cyl->orient);
	cyl_stat->y_in = dot_vecs(&cyl_stat->center2p_inner, &cyl->orient);
}

void	fill_front_point(t_cyl_stat *s, t_front_point *pt, t_cylinder *c)
{
	t_vector	multi;

	if (s->y_out >= 0 && s->y_out <= c->height && s->t_outer >= 0)
	{
		pt->coord = s->p_outer;
		multi = mult_vecs(&c->orient, s->y_out);
		pt->reflec_dir = sub_vecs(&s->center2p_outer, &multi);
		normalize(&pt->reflec_dir);
		pt->length = len_vector(&s->cam, &pt->coord);
		pt->cam_dir = s->ray;
		pt->color = c->color;
	}
	else if (s->y_in >= 0 && s->y_in <= c->height && s->t_inner >= 0)
	{
		pt->coord = s->p_inner;
		multi = mult_vecs(&c->orient, s->y_in);
		pt->reflec_dir = sub_vecs(&multi, &s->center2p_inner);
		normalize(&pt->reflec_dir);
		pt->length = len_vector(&s->cam, &pt->coord);
		pt->cam_dir = s->ray;
		pt->color = c->color;
	}
}

t_front_point	colide_ray_and_cyl(t_vector *r, t_vector *c, t_cylinder *cyl)
{
	t_front_point	front_point;
	t_cyl_dis		cyl_dis;
	t_cyl_stat		cyl_stat;

	front_point.length = 0;
	cyl_stat.ray = *r;
	cyl_stat.cam = *c;
	cyl_discriminant(&cyl_dis, r, c, cyl);
	if (cyl_dis.d < 0)
		return (front_point);
	make_cyl_stat(&cyl_dis, &cyl_stat, cyl);
	fill_front_point(&cyl_stat, &front_point, cyl);
	return (front_point);
}
