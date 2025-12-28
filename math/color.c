/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 02:54:47 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/28 21:14:00 by hamel-yo         ###   ########.fr       */
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
	t_color	new;

	new.r = c1.r * scalar;
	if (new.r > 255)
		new.r = 255;
	new.g = c1.g * scalar;
	if (new.g > 255)
		new.g = 255;
	new.b = c1.b * scalar;
	if (new.b > 255)
		new.b = 255;
	return (new);
}
