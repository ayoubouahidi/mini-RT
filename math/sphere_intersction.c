/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 02:54:38 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/28 20:28:57 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mrt.h"

double	delta(t_ray ray, t_plane p, double rad_square, t_tuple *s)
{
	t_tuple	oc;
	t_tuple	abc;
	t_tuple	das;

	oc = tuple_sub(ray.origin, p.point);
	if (s)
	{
		oc = tuple_sub(oc, tuple_mul(dot_pro(oc, p.n_vector), p.n_vector));
		ray.direction = tuple_sub(ray.direction,
				tuple_mul(dot_pro(ray.direction, p.n_vector), p.n_vector));
	}
	abc.x = dot_pro(ray.direction, ray.direction);
	abc.y = 2 * dot_pro(ray.direction, oc);
	abc.z = dot_pro(oc, oc) - rad_square;
	das.x = abc.y * abc.y - 4 * abc.x * abc.z;
	if (das.x < 0)
		return (-1);
	das.y = (-abc.y + sqrt(das.x)) / (2 * abc.x);
	das.z = (-abc.y - sqrt(das.x)) / (2 * abc.x);
	if (s)
		s->v = das.y;
	if ((das.y > das.z && das.y * das.z < 0)
		|| (das.y < das.z && das.y * das.z > 0 && das.y >= 0))
		return (das.y);
	return (das.z);
}

t_tuple	get_nsphere(t_sphere sphere, t_tuple point)
{
	t_tuple	normal;

	normal = tuple_sub(point, sphere.center);
	return (normalize_tuple(normal));
}

void	get_fsphere(t_ray ray, t_scene *scene, double *in)
{
	t_sphere	*f_sphere;
	t_plane		p;
	double		tmp;

	f_sphere = scene->sphere;
	scene->sphere = NULL;
	while (f_sphere)
	{
		p.point = f_sphere->center;
		p.n_vector = (t_tuple){0, 0, 0, 0};
		tmp = delta(ray, p, f_sphere->rad_square, NULL);
		if (tmp >= 0 && *in > tmp)
		{
			*in = tmp;
			scene->sphere = f_sphere;
		}
		f_sphere = f_sphere->next;
	}
}

t_ray	get_twopvec(t_tuple p1, t_tuple p2)
{
	t_ray	ray;

	ray.direction = tuple_sub(p1, p2);
	ray.direction = normalize_tuple(ray.direction);
	ray.origin = p1;
	return (ray);
}
