/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_a_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:12:13 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/28 20:35:32 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"
#include "../include/math.h"

t_ambient_light	pars_a_light(char **args)
{
	t_ambient_light	a_light;
	static t_uchar	nbr;

	if (nbr)
		parsing_error("the number of ambient light should be one\n");
	nbr++;
	a_light.ratio = pars_ratio(args[1]);
	a_light.ratio /= PI;
	a_light.color = pars_color(args[2]);
	return (a_light);
}
