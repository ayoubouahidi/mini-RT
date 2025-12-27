/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <hamel-yo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:45:07 by hamel-yo          #+#    #+#             */
/*   Updated: 2024/11/14 21:19:19 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] != 0)
	{
		if (i + 1 < dstsize)
			dst[i] = src[i];
		if (i + 1 == dstsize)
			dst[i] = 0;
		i++;
	}
	if (src[i] == 0 && i < dstsize)
		dst[i] = 0;
	return (i);
}
