/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:11:57 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/01/19 22:05:35 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(t_list *ls)
{
	int	i;
	int	l;

	i = 0;
	while (ls != NULL)
	{
		l = 0;
		while ((ls->content)[l] != 0)
			l++;
		i = i + l;
		ls = ls->next;
	}
	return (i);
}

void	ft_free_list(t_list **ls)
{
	t_list	*save;

	while (*ls != NULL)
	{
		save = (*ls)->next;
		free((*ls)->content);
		free(*ls);
		*ls = save;
	}
}

void	ft_check(int read_byte, t_list **ls, char **buffer, int *fd)
{
	if (read_byte < 1)
	{
		free (*buffer);
		if (read_byte == -1)
			ft_free_list(ls);
		*buffer = NULL;
		*fd = -1;
	}
	else
		(*buffer)[read_byte] = 0;
}

char	*ft_changestr(char **buffer, size_t i)
{
	char	*str ;
	size_t	l;

	l = 0;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	while (l < i)
	{
		str[l] = (*buffer)[l];
		l++;
	}
	str[l] = 0;
	l = 0;
	while ((*buffer)[i + l] != 0)
	{
		(*buffer)[l] = (*buffer)[i + l];
		l++;
	}
	(*buffer)[l] = 0;
	return (str);
}

char	*ft_strdup(char **buffer, int *fd)
{
	size_t	i;
	char	*str;

	i = 0;
	while ((*buffer)[i] != 0)
	{
		if ((*buffer)[i] == '\n')
		{
			*fd = -1;
			if ((*buffer)[i + 1] != 0)
				return (ft_changestr(buffer, i + 1));
		}
		i++;
	}
	str = *buffer;
	*buffer = NULL;
	return (str);
}
