/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 02:54:47 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/28 15:24:51 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mrt.h"

t_color	add_color(t_color c1, t_color c2)
{
	t_color	new;

	new.r = c1.r + c2.r;
	if (new.r > 255)
		new.r = 255;
	new.g = c1.g + c2.g;
	if (new.g > 255)
		new.g = 255;
	new.b = c1.b + c2.b;
	if (new.b > 255)
		new.b = 255;
	return (new);
}

t_color	sub_color(t_color c1, t_color c2)
{
	t_color	new;

	new.r = c1.r - c2.r;
	if (new.r > 255)
		new.r = 255;
	new.g = c1.g - c2.g;
	if (new.g > 255)
		new.g = 255;
	new.b = c1.b - c2.b;
	if (new.b > 255)
		new.b = 255;
	return (new);
}

t_color	mul_color(t_color c1, t_color c2)
{
	t_color	new;

	new.r = c1.r * c2.r;
	if (new.r > 255)
		new.r = 255;
	new.g = c1.g * c2.g;
	if (new.g > 255)
		new.g = 255;
	new.b = c1.b * c2.b;
	if (new.b > 255)
		new.b = 255;
	return (new);
}

t_color	mbs_color(double scalar, t_color c1)
{
	t_ushort	tmp;
	t_color	new;

	tmp = c1.r * scalar;
	if (tmp > 255)
		new.r = 255;
	else
		new.r = tmp;
	tmp = c1.g * scalar;
	if (tmp > 255)
		new.g = 255;
	else
		new.g = tmp;
	tmp = c1.b * scalar;
	if (tmp > 255)
		new.b = 255;
	else
		new.b = tmp;
	return (new);
}
