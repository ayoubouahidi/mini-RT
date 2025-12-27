/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:08:57 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/16 03:32:19 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mrt.h"

void	parsing_error(char *s)
{
	ft_putstr_fd(s, 2);
	gc(0);
	exit(1);
}

void	exit_mrt(char *s)
{
	ft_putstr_fd(s, 2);
	exit (1);
}

void	*gc(size_t size)
{
	void			*ptr;
	t_list			*node;
	static t_list	*list;

	if (!size)
	{
		ft_lstclear(&list, free);
		exit(0);
	}
	ptr = ft_calloc(size, 1);
	if (!ptr)
	{
		ft_lstclear(&list, free);
		exit_mrt(MEMORY_MSG);
	}
	node = ft_lstnew(ptr);
	if (!node)
	{
		ft_lstclear(&list, free);
		free(ptr);
		exit_mrt(MEMORY_MSG);
	}
	ft_lstadd_back(&list, node);
	return (ptr);
}
