/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <hamel-yo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:46:24 by hamel-yo          #+#    #+#             */
/*   Updated: 2024/11/21 09:43:42 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ls;

	if (*lst == NULL || del == NULL)
		return ;
	while ((*lst) != NULL)
	{
		ls = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = ls;
	}
	*lst = NULL;
}
