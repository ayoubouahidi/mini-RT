/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <hamel-yo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:48:30 by hamel-yo          #+#    #+#             */
/*   Updated: 2024/11/19 20:36:06 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str ;

	str = (char *)s;
	while (*str != 0)
	{
		if (*str == (char )c)
			return (str);
		str++;
	}
	if (*str == (char )c)
		return (str);
	return (NULL);
}
