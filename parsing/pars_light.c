/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:12:35 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/15 17:34:05 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"

t_light	*new_light(char **args)
{
	t_light	*light;

	light = gc(sizeof(t_light));
	light->point = pars_coordinate(args[1], 1);
	light->b_ratio = pars_ratio(args[2]);
	light->color = pars_color(args[3]);
	return (light);
}

void	pars_light(t_light **light, char **args)
{
	t_light	*l;
	t_light	*back;

	back = new_light(args);
	if (*light == NULL)
	{
		*light = back;
		return ;
	}
	l = *light;
	while (l->next != NULL)
		l = l->next;
	l->next = back;
}
