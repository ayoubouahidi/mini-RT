/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <hamel-yo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 02:00:01 by hamel-yo          #+#    #+#             */
/*   Updated: 2024/11/21 09:47:23 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ls;
	t_list	*node;
	void	*c;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	ls = NULL;
	while (lst != NULL)
	{
		c = f(lst->content);
		node = ft_lstnew(c);
		if (node == NULL)
		{
			ft_lstclear(&ls, del);
			free(c);
			return (NULL);
		}
		ft_lstadd_back(&ls, node);
		lst = lst->next;
	}
	return (ls);
}
