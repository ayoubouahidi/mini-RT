/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 02:55:03 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/28 14:12:56 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mrt.h"

t_tuple	tuple_zero(void)
{
	t_tuple	zero;

	zero.x = 0;
	zero.y = 0;
	zero.z = 0;
	zero.v = 0;
	return (zero);
}

t_tuple	tuple_add(t_tuple v, t_tuple u)
{
	t_tuple	new_v;

	new_v.x = v.x + u.x;
	new_v.y = v.y + u.y;
	new_v.z = v.z + u.z;
	new_v.v = v.v + u.v;
	return (new_v);
}

t_tuple	tuple_sub(t_tuple v, t_tuple u)
{
	t_tuple	new_v;

	new_v.x = v.x - u.x;
	new_v.y = v.y - u.y;
	new_v.z = v.z - u.z;
	new_v.v = v.v - u.v;
	return (new_v);
}

double	magnitude(t_tuple v)
{
	double	meg;

	v.x = v.x * v.x;
	v.y = v.y * v.y;
	v.z = v.z * v.z;
	meg = v.x + v.y + v.z;
	meg = sqrt(meg);
	return (meg);
}

t_tuple	get_point(t_ray ray, double t)
{
	t_tuple	point;

	point = tuple_mul(t, ray.direction);
	point = tuple_add(point, ray.origin);
	return (point);
}
