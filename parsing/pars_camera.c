/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 03:22:57 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/23 19:31:12 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"
#include "../include/math.h"

t_camera	pars_camera(char **args)
{
	t_camera		camera;
	int				fov;
	static t_uchar	nbr;

	if (nbr)
		parsing_error("the number of camera should be one\n");
	nbr++;
	camera.viewpoint = pars_coordinate(args[1], 1);
	camera.forward = pars_vector(args[2]);
	fov = ft_atof(args[3]);
	if (fov > 180 || fov < 0)
		parsing_error("error on the field of viwe\n");
	camera.fov = (double)fov / 180.0 * PI;
	get_helf_wh(camera.fov);
	return (camera);
}
