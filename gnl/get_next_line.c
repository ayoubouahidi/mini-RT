/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:27:44 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/01/19 22:07:00 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_make_node(t_list **ls, t_list **node, char **buffer, int *fd)
{
	if (*node == NULL || *buffer == NULL)
	{
		free(*buffer);
		*buffer = NULL;
		ft_free_list(ls);
		return ;
	}
	(*node)->content = ft_strdup(buffer, fd);
	(*node)->next = NULL;
	if ((*node)->content == NULL)
	{
		free (*node);
		*node = NULL;
		free(*buffer);
		*buffer = NULL;
		ft_free_list(ls);
	}
}

void	ft_make_list(t_list **ls, char **buffer, int *fd)
{
	t_list	*save;
	t_list	*node;

	save = *ls;
	node = malloc(sizeof(t_list));
	ft_make_node(ls, &node, buffer, fd);
	if (save == NULL && node != NULL)
	{
		*ls = node;
		return ;
	}
	if (*ls != NULL)
	{
		while ((*ls)->next != NULL)
			*ls = (*ls)->next;
		(*ls)->next = node;
		*ls = save;
	}
}

void	ft_get_list(char **buffer, t_list **ls, int *fd)
{
	int	read_byte;

	if (*buffer == NULL)
	{
		*buffer = malloc(sizeof(char) * (((size_t)BUFFER_SIZE + 1)));
		read_byte = read(*fd, *buffer, BUFFER_SIZE);
		ft_check(read_byte, ls, buffer, fd);
	}
	if (*fd != -1 && *buffer != NULL)
		ft_make_list(ls, buffer, fd);
}

char	*ft_strjoin(t_list *ls)
{
	char	*line;
	size_t	size_of_line;
	int		i;
	int		l;

	i = 0;
	if (ls == NULL)
		return (NULL);
	size_of_line = ft_strlen(ls);
	line = malloc(sizeof(char) * (size_of_line + 1));
	if (line == NULL)
		return (NULL);
	while (ls != NULL)
	{
		l = 0;
		while ((ls->content)[l] != 0)
		{
			line[i] = (ls->content)[l];
			l++;
			i++;
		}
		ls = ls->next;
	}
	line[i] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	t_list		*ls;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
	{
		free(buffer);
		return (NULL);
	}
	ls = NULL;
	while (fd != -1)
		ft_get_list(&buffer, &ls, &fd);
	line = ft_strjoin(ls);
	ft_free_list(&ls);
	return (line);
}
