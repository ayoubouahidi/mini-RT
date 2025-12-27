/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <hamel-yo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:40:50 by hamel-yo          #+#    #+#             */
/*   Updated: 2024/11/18 17:43:40 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0 ;
	if (lst != NULL)
	{
		i++;
		while (lst->next != NULL)
		{
			i++;
			lst = lst->next;
		}
	}
	return (i);
}
