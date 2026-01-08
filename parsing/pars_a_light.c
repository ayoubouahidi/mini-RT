/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_a_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:12:13 by hamel-yo          #+#    #+#             */
/*   Updated: 2026/01/08 16:43:06 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"
#include "../include/math.h"

t_ambient_light	pars_a_light(char **args)
{
	t_ambient_light	a_light;
	static t_uchar	nbr;

	ft_memset(&a_light, sizeof(t_ambient_light), 0);
	if ((args && nbr) || (!args && !nbr))
	{
		parsing_error("the number of ambient light should be one\n");
		return (a_light);
	}
	if (!args)
		return (a_light);
	nbr++;
	a_light.ratio = pars_ratio(args[1]);
	a_light.ratio *= 0.1;
	a_light.color = pars_color(args[2]);
	return (a_light);
}
