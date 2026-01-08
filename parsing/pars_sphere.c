/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:13:06 by hamel-yo          #+#    #+#             */
/*   Updated: 2026/01/08 05:59:51 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"

t_sphere	*new_sphere(char **args)
{
	t_sphere	*sphere;

	sphere = gc(sizeof(t_sphere));
	sphere->center = pars_coordinate(args[1], 1);
	if (string_is_null(args[2]))
		return (sphere);
	sphere->rad_square = ft_atof(args[2]);
	if (sphere->rad_square <= 0)
		parsing_error("sphere diameter should be positive\n");
	sphere->rad_square = pow(sphere->rad_square / 2, 2);
	sphere->color = pars_color(args[3]);
	return (sphere);
}

void	pars_sphere(t_sphere **sphere, char **args)
{
	t_sphere	*h;
	t_sphere	*new;

	new = new_sphere(args);
	if (*sphere == NULL)
	{
		*sphere = new;
		return ;
	}
	h = *sphere;
	while (h->next)
		h = h->next;
	h->next = new;
}
