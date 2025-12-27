/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 21:26:20 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/24 20:26:44 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mrt.h"

double	disk_in(t_ray ray, t_cylinder cy, t_tuple ct)
{
	t_tuple	p;
	double	denom;
	double	t;

	denom = dot_pro(ray.direction, cy.n_vector);
	t = dot_pro(tuple_sub(ct, ray.origin), cy.n_vector) / denom;
	if (t < 0 || denom == 0)
		return (-1);
	p = tuple_add(ray.origin, tuple_mul(t, ray.direction));
	p = tuple_sub(p, ct);
	p.v = dot_pro(p, p);
	if (p.v <= cy.rad_square)
		return (p.v);
	return (-1);
}

double	cylinder_in(t_ray ray, t_cylinder cy)
{
	t_tuple	t;
	t_tuple	p;
	double	m;

	t.z = cy.height /2;
	t.x = delta(ray, cy.center, cy.n_vector, cy.rad_square, &t);
	if (t.x == -1)
		return (-1);
	t.y = ray.origin.y + t.x * ray.direction.y;
	p = tuple_add(ray.origin, tuple_mul(t.x, ray.direction));
	m = dot_pro(tuple_sub(p, cy.center), cy.n_vector);
	if (m <= t.z && m >= -t.z)
		return (t.x);
	t.x = t.v;
	t.y = ray.origin.y + t.x * ray.direction.y;
	p = tuple_add(ray.origin, tuple_mul(t.x, ray.direction));
	m = dot_pro(tuple_sub(p, cy.center), cy.n_vector);
	if (m <= t.z && m >= -t.z)
		return (t.x);
	return (-1);
}

void	get_fcylinder(t_ray ray, t_scene *scene, double *in)
{
	t_cylinder	*f_cylinder;
	double		tmp;

	f_cylinder = scene->cylinder;
	scene->cylinder = NULL;
	while (f_cylinder)
	{
		tmp = cylinder_in(ray, *f_cylinder);
		if (tmp >= 0 && *in > tmp)
		{
			scene->sphere = NULL;
			*in = tmp;
			scene->cylinder = f_cylinder;
		}
		f_cylinder = f_cylinder->next;
	}
}

t_tuple	get_ncylinder(t_cylinder cy, t_tuple p)
{
	t_tuple	n;
	double	dot;

	n = tuple_sub(p, cy.center);
	dot = dot_pro(n, cy.n_vector);
	n = tuple_add(cy.center, tuple_mul(dot, cy.n_vector));
	n = tuple_sub(p, n);
	return (n);
}
