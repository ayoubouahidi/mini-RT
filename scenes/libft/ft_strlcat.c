/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <hamel-yo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:45:45 by hamel-yo          #+#    #+#             */
/*   Updated: 2024/11/20 21:10:04 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dl;

	if (dstsize == 0)
		return (ft_strlen(src));
	dl = ft_strlen(dst);
	if (dl > dstsize)
		return (ft_strlen(src) + dstsize);
	i = 0;
	while (src[i] != '\0' && i + dl < dstsize - 1)
	{
		dst[dl + i] = src[i];
		i++;
	}
	dst[dl + i] = 0;
	return (dl + ft_strlen(src));
}

// NULL, NULL, 0
// NULL, NULL, 1
// "", NULL, 3
// "", "", 0
// NULL, "", 0
// NULL, "", 45
// "", "", 45
