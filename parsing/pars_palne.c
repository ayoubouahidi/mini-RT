/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_palne.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:12:45 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/15 17:26:46 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"

t_plane	*new_plane(char **args)
{
	t_plane	*plane;

	plane = gc(sizeof(t_plane));
	plane->point = pars_coordinate(args[1], 1);
	plane->n_vector = pars_vector(args[2]);
	plane->color = pars_color(args[3]);
	return (plane);
}

void	pars_plane(t_plane **plane, char **args)
{
	t_plane	*h;
	t_plane	*new;

	new = new_plane(args);
	if (*plane == NULL)
	{
		*plane = new;
		return ;
	}
	h = *plane;
	while (h->next)
		h = h->next;
	h->next = new;
}
