/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:13:14 by ayouahid          #+#    #+#             */
/*   Updated: 2025/01/05 13:13:16 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H 
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
#include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

// char	*ft_strdup(const char *s);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strchr(const char *str, int c);
// size_t	ft_strlen(const char *a);
char	*get_next_line(int fd);
char	*freenull(char *buff, char *readed);

#endif
