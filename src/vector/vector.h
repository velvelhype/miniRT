/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:39:25 by akito             #+#    #+#             */
/*   Updated: 2022/05/21 11:39:25 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include "simple_operation.h"

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

double		len_vector(t_vector	*v1, t_vector *v2);
void		init_vector(t_vector *vec, double x, double y, double z);
t_vector	add_vecs(const t_vector *a, const t_vector *b);
t_vector	sub_vecs(const t_vector *a, const t_vector *b);
t_vector	mult_vecs(const t_vector *a, double b);
double		dot_vecs(const t_vector *a, const t_vector *b);
void		cross_vecs(t_vector *o, const t_vector *a, const t_vector *b);
double		squared_norm(const t_vector *v);
double		norm(const t_vector *v);
double		normalize(t_vector *v);
void		print_vecs(t_vector *vec);

#endif
