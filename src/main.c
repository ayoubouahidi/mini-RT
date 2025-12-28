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

t_mlx	*get_mlx_data(char *file_name);

void	cleanup_mlx(void)
{
    t_mlx	*mlx;

    mlx = get_mlx_data(NULL);
    if (mlx->image)
        mlx_destroy_image(mlx->init, mlx->image);
    if (mlx->win)
        mlx_destroy_window(mlx->init, mlx->win);
    if (mlx->init)
    {
        mlx_destroy_display(mlx->init);
        free(mlx->init);
    }
}

int	handle_keypress(int keycode, t_scene *scene)
{
	(void)scene;

	if (keycode == 65307)
	{
		cleanup_mlx();
		gc(1);
		exit(0);
	}
	return (0);
}

int	handle_close_window(t_scene *scene)
{
	(void)scene;
	cleanup_mlx();
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
