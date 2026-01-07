/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:16:15 by hamel-yo          #+#    #+#             */
/*   Updated: 2026/01/07 06:12:36 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mrt.h"

bool	is_in_shadow(t_scene full_scene, t_tuple point, t_light *light)
{
	t_tuple	to_light;
	t_ray	sray;
	double	max_dist;
	double	in;

	to_light = tuple_sub(light->point, point);
	max_dist = magnitude(to_light);
	sray.direction = normalize_tuple(to_light);
	sray.origin = tuple_add(point, tuple_mul(0.001, sray.direction));
	in = get_first_intersction(sray, full_scene, NULL);
	if (in > 0 && in < max_dist - 0.001)
		return (true);
	return (false);
}

t_color	get_ambient(t_color obc, t_ambient_light a_light)
{
	obc = mul_color(obc, a_light.color);
	obc = mbs_color(a_light.ratio, obc);
	return (obc);
}

t_color	get_diffuse(double dot, t_light l, t_color obc)
{
	dot = fmax(dot, 0.0);
	l.color = mbs_color(l.b_ratio, l.color);
	l.color = mul_color(obc, l.color);
	l.color = mbs_color(dot, l.color);
	return (l.color);
}

t_color	get_speculer(t_plane point, t_ray ray, t_ray lray, t_light light)
{
	double	dot;
	t_tuple	r;
	t_color	diffuse;

	dot = dot_pro(point.n_vector, lray.direction);
	diffuse = get_diffuse(dot, light, point.color);
	dot = 2.0 * dot;
	point.n_vector = tuple_mul(dot, point.n_vector);
	r = tuple_sub(point.n_vector, lray.direction);
	r = normalize_tuple(r);
	ray.direction = tuple_mul(-1, ray.direction);
	ray.direction = normalize_tuple(ray.direction);
	dot = fmax(dot_pro(r, ray.direction), 0.0);
	dot *= light.b_ratio;
	dot = pow(dot, 64.0);
	light.color = mbs_color(dot, light.color);
	return (add_color(diffuse, light.color));
}

t_color	get_pixel(t_scene scene, t_scene full_scene, t_plane point, t_ray ray)
{
	t_color	ambint;
	t_color	speculer;
	t_ray	lray;

	ambint = get_ambient(point.color, scene.ambient_light);
	while (scene.light)
	{
		lray.direction = normalize_tuple(tuple_sub(
					scene.light->point, point.point));
		lray.origin = scene.light->point;
		if (!is_in_shadow(full_scene, point.point, scene.light))
		{
			speculer = get_speculer(point, ray, lray, *scene.light);
			ambint = add_color(speculer, ambint);
		}
		scene.light = scene.light->next;
	}
	return (ambint);
}
