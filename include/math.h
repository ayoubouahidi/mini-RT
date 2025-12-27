/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 08:58:53 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/24 20:41:02 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# define EPSIlON 0.00001
# define PI 3.14159265358979323846264338

#include "parse.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
	double	ray_intersection;
}	t_ray;

t_tuple	get_point(t_ray ray, double t);
t_tuple	get_nplane(t_tuple pdir, t_tuple rdir);
t_tuple	get_ncylinder(t_cylinder cy, t_tuple p);
t_tuple	get_nsphere(t_sphere sphere, t_tuple point);
double	delta(t_ray ray, t_tuple c, t_tuple c_axis, double rad_square, t_tuple *s);
t_color	get_first_intersction(t_ray ray, t_scene scene);
void	get_fplane(t_ray ray, t_scene *scene, double *in);
void	get_fcylinder(t_ray ray, t_scene *scene, double *in);
void	get_fsphere(t_ray ray, t_scene *scene, double *in);
double	aspect(void);
t_color	add_color(t_color c1, t_color c2);
t_color	sub_color(t_color c1, t_color c2);
t_color	mbs_color(double scalar, t_color c1);
t_color	mul_color(t_color c1, t_color c2);
t_tuple	get_helf_wh(double fov_rad);
double	dot_pro(t_tuple v, t_tuple u);
t_tuple	cross_product(t_tuple v1, t_tuple v2);
t_tuple	normalize_tuple(t_tuple tuple);
t_tuple	tuple_mul(double i, t_tuple vec);
t_tuple	tuple_div(double i, t_tuple vec);
t_tuple	tuple_sub(t_tuple v, t_tuple u);
t_tuple	tuple_add(t_tuple v, t_tuple u);
double	square(double x);
t_tuple	tuple_zero(void);
double	magnitude(t_tuple v);

#endif
