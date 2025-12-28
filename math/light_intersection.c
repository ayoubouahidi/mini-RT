/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 21:54:54 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/28 21:37:10 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mrt.h"

t_color	get_fcolor(t_ray cray, double t, t_scene scene, t_scene full_scene)
{
	t_plane	p;

	p.point = get_point(cray, t);
	if (scene.sphere)
	{
		p.n_vector = get_nsphere(*scene.sphere, p.point);
		p.color = scene.sphere->color;
		return (get_pixel(scene, full_scene, p, cray));
	}
	else if (scene.cylinder)
	{
		p.n_vector = get_ncylinder(*scene.cylinder, p.point);
		p.color = scene.cylinder->color;
		return (get_pixel(scene, full_scene, p, cray));
	}
	else if (scene.plane)
	{
		p.n_vector = get_nplane(scene.plane->n_vector, cray.direction);
		p.color = scene.plane->color;
		return (get_pixel(scene, full_scene, p, cray));
	}
	return ((t_color){0, 0, 0});
}

double	get_first_intersction(t_ray ray, t_scene scene, t_color *color)
{
	double		in;
	t_scene		full_scene;

	in = DBL_MAX;
	full_scene = scene;
	get_fsphere(ray, &scene, &in);
	get_fcylinder(ray, &scene, &in);
	get_fplane(ray, &scene, &in);
	if (color)
		*color = get_fcolor(ray, in, scene, full_scene);
	return (in);
}
