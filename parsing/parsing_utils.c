/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:49:06 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/28 20:16:03 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"
#include "../include/math.h"

void	string_is_null(char *s)
{
	if (s == NULL)
		parsing_error("");
}

double	pars_ratio(char *s)
{
	double	ratio;

	string_is_null(s);
	ratio = ft_atof(s);
	if (ratio < 0 || ratio > 1)
	{
		parsing_error("the ratio range should be between -1 and 1\n");
		return (-1);
	}
	return (ratio);
}

t_color	pars_color(char *s)
{
	t_color	color;

	string_is_null(s);
	color.r = ft_atoi(s);
	while (*s != ',' && *s)
		s++;
	if (*s == 0)
		parsing_error("the color sould be composed from 3 numbers\n");
	s++;
	color.g = ft_atoi(s);
	while (*s != ',' && *s)
		s++;
	if (*s == 0)
		parsing_error("the color sould be composed from 3 numbers\n");
	s++;
	color.b = ft_atoi(s);
	if ((color.r < 0 || color.r > 255)
		|| (color.g < 0 || color.g > 255)
		|| (color.b < 0 || color.b > 255))
		parsing_error("the range of color should be between 0 and 255\n");
	return (color);
}

t_tuple	pars_coordinate(char *s, bool v)
{
	t_tuple	coordinate;

	string_is_null(s);
	coordinate.x = ft_atof(s);
	while (*s != ',' && *s)
		s++;
	if (*s == 0)
		parsing_error("the coordinate sould be composed from 3 numbers\n");
	s++;
	coordinate.y = ft_atof(s);
	while (*s != ',' && *s)
		s++;
	if (*s == 0)
		parsing_error("the coordinate sould be composed from 3 numbers\n");
	s++;
	coordinate.z = ft_atof(s);
	coordinate.v = v;
	return (coordinate);
}

t_tuple	pars_vector(char *s)
{
	t_tuple	vector;

	string_is_null(s);
	vector = pars_coordinate(s, 0);
	if ((vector.x < -1 || vector.x > 1)
		|| (vector.y < -1 || vector.y > 1)
		|| (vector.z < -1 || vector.z > 1))
		parsing_error("the range of unit vector should be between -1 and 1\n");
	vector = normalize_tuple(vector);
	return (vector);
}
