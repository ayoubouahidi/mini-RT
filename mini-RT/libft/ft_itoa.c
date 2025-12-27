/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <hamel-yo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:28:47 by hamel-yo          #+#    #+#             */
/*   Updated: 2024/11/10 18:29:26 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	ft_count(int n)
{
	unsigned char	c ;

	c = 0 ;
	if (n <= 0)
		c++;
	while (n != 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	unsigned char	size;
	unsigned int	nb ;
	char			*str;

	size = ft_count(n);
	nb = n ;
	str = ft_calloc (size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
		nb = -n ;
	while (nb != 0)
	{
		str[size - 1] = (nb % 10) + '0';
		nb = nb / 10;
		size--;
	}
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	return (str);
}
