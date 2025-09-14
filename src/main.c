/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:57:37 by ayouahid          #+#    #+#             */
/*   Updated: 2025/09/12 00:31:47 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/minirt.h"
#include "../libft/libft.h"
#include "../include/parse.h"

// void	init(t_scene *scene)
// {
// 	scene->ambient_light;

// }

int main(int ac, char **av)
{
	t_scene scene;

	
	// init(&scene);
	ft_bzero(&scene, sizeof(scene));
	if (valid_file(ac, av))
		return (1);
	
	parser_file(av[1], &scene);
}
