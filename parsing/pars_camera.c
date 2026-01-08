/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 03:22:57 by hamel-yo          #+#    #+#             */
/*   Updated: 2026/01/08 16:43:40 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"
#include "../include/math.h"

t_camera	pars_camera(char **args)
{
	t_camera		camera;
	int				fov;
	static t_uchar	nbr;

	ft_memset(&camera, sizeof(t_camera), 0);
	if ((args && nbr) || (!args && !nbr))
	{
		parsing_error("the number of camera should be one\n");
		return (camera);
	}
	if (!args)
		return (camera);
	nbr++;
	camera.viewpoint = pars_coordinate(args[1], 1);
	camera.forward = pars_vector(args[2]);
	if (string_is_null(args[3]))
		return (camera);
	fov = ft_atof(args[3]);
	if (fov > 180 || fov < 0)
		parsing_error("error on the field of viwe\n");
	camera.fov = (double)fov / 180.0 * PI;
	get_helf_wh(camera.fov);
	return (camera);
}
