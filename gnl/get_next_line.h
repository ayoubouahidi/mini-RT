/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 08:36:11 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/01/20 00:21:15 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
//# include <stdio.h>
//# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*content ;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*ft_strdup(char **buffer, int *fd);
char	*ft_changestr(char **buffer, size_t i);
int		ft_strlen(t_list *ls);
void	ft_free_list(t_list **ls);
void	ft_check(int read_byte, t_list **ls, char **buffer, int *fd);

#endif
