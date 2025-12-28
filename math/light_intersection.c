/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 21:54:54 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/28 15:21:09 by hamel-yo         ###   ########.fr       */
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

t_color	get_speculer(double dot, t_ray ray, t_tuple nor, t_ray lray, t_light light)
{
	t_tuple	r;

	dot = 2.0 * dot;
	nor = tuple_mul(dot, nor);
	r = tuple_sub(nor, lray.direction);
	r = normalize_tuple(r);
	ray.direction = tuple_mul(-1, ray.direction);
	ray.direction = normalize_tuple(ray.direction);
	dot = fmax(dot_pro(r, ray.direction), 0.0);
	dot*= light.b_ratio;
	dot = pow(dot, 64.0);
	light.color = mbs_color(dot, light.color);
	return (light.color);
}

t_color	get_spherecolor(t_scene scene, t_scene full_scene, t_plane point, t_ray ray)
{
	t_color	ambint;
	t_color	diffuse;
	t_color	speculer;
	t_ray	lray;

	ambint = get_ambient(point.color, scene.ambient_light);
	while (scene.light)
	{
		lray.direction = normalize_tuple(tuple_sub(scene.light->point, point.point));
		lray.origin = scene.light->point;
		if (!is_in_shadow(full_scene, point.point, scene.light))
		{
			diffuse = get_diffuse(dot_pro(point.n_vector, lray.direction), *scene.light, point.color);
			speculer = get_speculer(dot_pro(point.n_vector, lray.direction), ray, point.n_vector, lray, *scene.light);
			speculer = add_color(diffuse, speculer);
			ambint = add_color(speculer, ambint);
		}
		scene.light = scene.light->next;
	}
	return (ambint);
}

t_color	get_fcolor(t_ray cray, double t, t_scene scene, t_scene full_scene)
{
	t_plane	p;

	p.point = get_point(cray, t);
	if (scene.sphere)
	{
		p.n_vector = get_nsphere(*scene.sphere, p.point);
		p.color = scene.sphere->color;
		return (get_spherecolor(scene, full_scene, p, cray));
	}
	else if (scene.cylinder)
	{
		p.n_vector = get_ncylinder(*scene.cylinder, p.point);
		p.color = scene.cylinder->color;
		return (get_spherecolor(scene, full_scene, p, cray));
	}
	else if (scene.plane)
	{
		p.n_vector = get_nplane(scene.plane->n_vector, cray.direction);
		p.color = scene.plane->color;
		return (get_spherecolor(scene, full_scene, p, cray));
	}
	return ((t_color){0, 0, 0});
}

double	get_first_intersction(t_ray ray, t_scene scene, t_color *color)
{
	double		in;
	t_scene    full_scene;

	in = DBL_MAX;
	full_scene = scene;
	get_fsphere(ray, &scene, &in);
	get_fcylinder(ray, &scene, &in);
	get_fplane(ray, &scene, &in);
	if (color)
		*color = get_fcolor(ray, in, scene, full_scene);
	return (in);
}
