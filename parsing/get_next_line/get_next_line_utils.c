/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:21:29 by ayouahid          #+#    #+#             */
/*   Updated: 2025/12/13 00:29:52 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

char	*gnl_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (!(char)c)
		return ((char *)&str[i]);
	return (NULL);
}

size_t	gnl_strlen(const char *a)
{
	size_t	i;

	i = 0;
	if (a == NULL)
		return (0);
	while (a[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*gnl_strdup(const char *s)
{
	char	*str;
	char	*newstr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	newstr = gc(sizeof(char) * gnl_strlen(str) + 1);
	i = 0;
	while (str[i] != '\0')
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	j = 0;
	if (!s1)
		return (gnl_strdup(s2));
	newstr = (char *)gc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	i = 0;
	while (i < gnl_strlen(s1))
	{
		newstr[i] = s1[i];
		i++;
	}
	while (j < gnl_strlen(s2))
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[j + i] = '\0';
	return (newstr);
}
