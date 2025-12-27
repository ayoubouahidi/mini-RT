/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 23:35:06 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/24 20:43:07 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mrt.h"

double	plane_in(t_ray ray, t_plane plane)
{
	t_tuple	oc;
	t_tuple	t;

	t.x = dot_pro(ray.direction, plane.n_vector);
	if (t.x < 0.0001 && -t.x < 0.0001)
		return (-1);
	oc = tuple_sub(plane.point, ray.origin);
	t.y = dot_pro(oc, plane.n_vector) / t.x;
	if (t.y < 0.001)
		return (-1);
	return(t.y);
}

t_tuple	get_nplane(t_tuple pdir, t_tuple rdir)
{
	if (dot_pro(pdir, rdir) >  0)
		pdir = tuple_mul(-1, pdir);
	return (pdir);
}

void	get_fplane(t_ray ray, t_scene *scene, double *in)
{
	t_plane	*f_plane;
	double		tmp;

	f_plane = scene->plane;
	scene->plane = NULL;
	while (f_plane)
	{
		tmp = plane_in(ray, *f_plane);
		if (tmp > 0 && *in > tmp)
		{
			scene->cylinder = NULL;
			scene->sphere = NULL;
			*in = tmp;
			scene->plane = f_plane;
		}
		f_plane = f_plane->next;
	}
}
