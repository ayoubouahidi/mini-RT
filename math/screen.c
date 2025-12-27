/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 02:57:26 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/19 12:14:51 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mrt.h"

double	aspect(void)
{
	return ((double)WIDTH / HEIGHT);
}

t_tuple	get_helf_wh(double fov_rad)
{
	static t_tuple	helf_wh;

	if (!fov_rad)
		return (helf_wh);
	helf_wh.x = tan(fov_rad / 2);
	helf_wh.y = helf_wh.x / aspect();
	return (helf_wh);
}
