/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <hamel-yo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 06:01:28 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/29 15:03:35 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	size_t	ft_count_word(char *s, char c)
{
	size_t	w;

	w = 0;
	while (*s != 0)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == 0))
			w++;
		s++ ;
	}
	return (w);
}

static	char	*ft_makestr(char **s, char c)
{
	size_t	i;
	char	*str;

	i = 0 ;
	while (s[0][i] != c && s[0][i] != 0)
		i++;
	str = (char *)gc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (**s != 0 && **s != c)
	{
		str[i] = **s;
		i++;
		(*s)++;
	}
	return (str);
}

static	void	*ft_free(char **strs, int i)
{
	while (i >= 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
	return (NULL);
}

static	char	**ft_nullstr(void)
{
	char	**str;

	str = (char **)gc(2 * sizeof(char *));
	if (str == NULL)
		return (NULL);
	str[0] = ft_strdup("");
	if (str[0] == NULL)
		return (ft_free(str, 0));
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	w;
	size_t	i;
	char	**strs;

	if (s == NULL)
		return (ft_nullstr());
	w = ft_count_word((char *)s, c);
	strs = (char **) malloc((w + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	i = 0;
	while (*s != 0 && i < w)
	{
		if (*s != c)
		{
			strs[i] = ft_makestr((char **)&s, c);
			if (strs[i] == NULL)
				return (ft_free(strs, (int)i));
			i++;
		}
		if (*s != 0)
			s++;
	}
	return (strs);
}
