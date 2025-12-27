/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 02:55:32 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/16 10:37:19 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mrt.h"

t_tuple	tuple_mul(double i, t_tuple vec)
{
	t_tuple	new;

	new.x = vec.x * i;
	new.y = vec.y * i;
	new.z = vec.z * i;
	new.v = vec.v * i;
	return (new);
}

t_tuple	tuple_div(double i, t_tuple vec)
{
	t_tuple	new;

	new.x = vec.x / i;
	new.y = vec.y / i;
	new.z = vec.z / i;
	new.v = vec.v / i;
	return (new);
}

t_tuple	normalize_tuple(t_tuple tuple)
{
	double	mag;

	mag = magnitude(tuple);
	if (mag == 1)
		return (tuple);
	return (tuple_div(mag, tuple));
}

t_tuple	cross_product(t_tuple v1, t_tuple v2)
{
	t_tuple	v;

	v.x = (v1.y * v2.z) - (v1.z * v2.y);
	v.y = (v1.z * v2.x) - (v1.x * v2.z);
	v.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (v);
}

double	dot_pro(t_tuple v, t_tuple u)
{
	double	i;

	i = v.x * u.x + v.y * u.y + v.z * u.z;
	return (i);
}
