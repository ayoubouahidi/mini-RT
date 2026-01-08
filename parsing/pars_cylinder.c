/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:12:27 by hamel-yo          #+#    #+#             */
/*   Updated: 2026/01/08 05:57:11 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"
#include "../include/math.h"

t_cylinder	*new_cylinder(char **args)
{
	t_cylinder	*cylinder;

	cylinder = gc(sizeof(t_cylinder));
	cylinder->center = pars_coordinate(args[1], 1);
	cylinder->n_vector = pars_vector(args[2]);
	if (string_is_null(args[3]) || string_is_null(args[4]))
		return (cylinder);
	cylinder->rad_square = ft_atof(args[3]);
	cylinder->height = ft_atof(args[4]);
	if (cylinder->rad_square < 0 || cylinder->height < 0)
		parsing_error("the height and diameter should be positive\n");
	cylinder->rad_square = pow(cylinder->rad_square / 2, 2);
	cylinder->color = pars_color(args[5]);
	return (cylinder);
}

void	pars_cylinder(t_cylinder **cylinder, char **args)
{
	t_cylinder	*h;
	t_cylinder	*new;

	new = new_cylinder(args);
	if (*cylinder == NULL)
	{
		*cylinder = new;
		return ;
	}
	h = *cylinder;
	while (h->next)
		h = h->next;
	h->next = new;
}
