/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:57:37 by ayouahid          #+#    #+#             */
/*   Updated: 2025/12/28 20:45:19 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mrt.h"

void	print_scene(t_scene scene);

int	handle_keypress(int keycode, t_scene *scene)
{
	(void)scene;
	if (keycode == 65307)
	{
		gc(1);
		exit(0);
	}
	return (0);
}

int	handle_close_window(t_scene *scene)
{
	(void)scene;
	gc(1);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_scene	scene;

	scene = pars_scene(ac, av);
	put_imageonwindow(&scene, av[1]);
	mlx_hook(scene.win_ptr, 2, 1L << 0, handle_keypress, &scene);
	mlx_hook(scene.win_ptr, 17, 1L << 17, handle_close_window, &scene);
	mlx_loop(scene.mlx_ptr);
	mlx_loop(scene.mlx_ptr);
	gc(0);
}
