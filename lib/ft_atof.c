/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:34:03 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/13 02:53:37 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static float	ft_int(char **s)
{
	float	f;

	f = 0;
	while (**s >= '0' && **s <= '9')
	{
		f = f * 10 + (**s - '0');
		*s += 1;
	}
	if (**s == '.')
		*s += 1;
	return (f);
}

static float	ft_float(char **s)
{
	float	f;
	float	comma;

	comma = 0.1;
	f = 0;
	while (**s >= '0' && **s <= '9')
	{
		f += comma * (**s - '0');
		*s += 1;
		comma *= 0.1;
	}
	if (**s == '.')
		parsing_error("double comma in the same value\n");
	return (f);
}

static int	skip(char **s)
{
	while ((**s >= '\t' && **s <= 13) || **s == 32)
		*s += 1;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
		{
			*s += 1;
			return (-1);
		}
		else
			*s += 1;
	}
	return (1);
}

float	ft_atof(char *s)
{
	float	f;
	int		sign;

	sign = skip(&s);
	f = ft_int(&s);
	f += ft_float(&s);
	return (sign * f);
}
