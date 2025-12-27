/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:30:39 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/22 08:39:01 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mrt.h"

t_tuple	world_up(t_tuple c_forward)
{
	t_tuple	w_up;

	w_up.x = 0;
	if (c_forward.x == 0 && c_forward.y == 1 && c_forward.z == 0)
	{
		w_up.y = 0;
		w_up.z = 1;
	}
	else
	{
		w_up.y = 1;
		w_up.z = 0;
	}
	return (w_up);
}

t_tuple	get_right(t_tuple *up, t_tuple forward)
{
	t_tuple	right;

	*up = world_up(forward);
	right = cross_product(*up, forward);
	right = normalize_tuple(right);
	*up = cross_product(forward, right);
	return (right);
}

t_tuple	get_ray_direction(t_ushort x, t_ushort y, t_tuple forward)
{
	t_tuple	up;
	t_tuple	direction;
	t_tuple	right;
	t_tuple	helf;

	helf = get_helf_wh(0);
	right = get_right(&up, forward);
	helf.z = ((2.0 * x / WIDTH) - 1.0) * helf.x;
	helf.v = (1.0 - (2.0 * y / HEIGHT)) * helf.y;
	direction = tuple_add(forward, tuple_mul(helf.z, right));
	direction = tuple_add(direction, tuple_mul(helf.v, up));
	return (normalize_tuple(direction));
}

t_ray	get_ray(t_ushort x, t_ushort y, t_camera camera)
{
	t_ray	ray;

	ray.direction = get_ray_direction(x, y, camera.forward);
	ray.origin = camera.viewpoint;
	return (ray);
}
