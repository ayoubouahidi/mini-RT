/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <hamel-yo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 03:08:30 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/16 03:45:25 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	isit(char c, char const *set)
{
	if (set == NULL)
		return (0);
	while (*set != 0)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		o ;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	while (isit(*s1, set) == 1 && *s1 != 0)
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && isit(s1[len - 1], set) == 1)
		len--;
	str = (char *)gc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	o = 0;
	while (s1[o] != 0 && o < len)
	{
		str[o] = s1[o];
		o++;
	}
	str[o] = 0;
	return (str);
}
