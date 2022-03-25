#ifndef VECTOR_H
# define VECTOR_H

# include "simple_operation.h"

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

float		len_vector(t_vector	*v1, t_vector *v2);
void		init_vector(t_vector *vec, float arg_x, float arg_y, float arg_z);
t_vector	add_vecs(const t_vector *a, const t_vector *b);
t_vector	sub_vecs(const t_vector *a, const t_vector *b);
t_vector	mult_vecs(const t_vector *a, float b);
float		dot_vecs(const t_vector *a, const t_vector *b);
void		cross_vecs(t_vector *o, const t_vector *a, const t_vector *b);
float		squared_norm(const t_vector *v);
float		norm(const t_vector *v);
float		normalize(t_vector *v);

#endif
