/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 04:54:55 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/28 20:52:48 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mrt.h"

t_mlx	*get_mlx_data(char *file_name)
{
	static t_mlx	mlx;

	if (!file_name)
		return (&mlx);
	mlx.init = mlx_init();
	if (!mlx.init)
		parsing_error("error on mlx init\n");
	mlx.win = mlx_new_window(mlx.init, WIDTH, HEIGHT, file_name);
	if (!mlx.win)
		parsing_error("error on open the window\n");
	mlx.image = mlx_new_image(mlx.init, WIDTH, HEIGHT);
	if (!mlx.image)
		parsing_error("error on the creation of the image\n");
	mlx.addr = mlx_get_data_addr(mlx.image, &mlx.bpp, &mlx.s_line, &mlx.endian);
	mlx.bpp /= 8;
	return (&mlx);
}

void	convert_ctop(t_color c, int *p)
{
	t_uchar	*bite;

	bite = (t_uchar *)p;
	bite[2] = c.r;
	bite[1] = c.g;
	bite[0] = c.b;
}

void	put_pixel(int x, int y, t_color color)
{
	int		pixel;
	t_uchar	*ptr;
	t_mlx	*mlx;

	mlx = get_mlx_data(NULL);
	convert_ctop(color, &pixel);
	ptr = mlx->addr + y * mlx->s_line + x * mlx->bpp;
	*(int *)ptr = pixel;
}

void	put_imageonwindow(t_scene *scene, char *f_name)
{
	t_mlx		*mlx;
	t_ray		ray;
	t_color		color;
	t_ushort	x;
	t_ushort	y;

	mlx = get_mlx_data(f_name);
	scene->win_ptr = mlx->win;
	scene->mlx_ptr = mlx->init;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = get_ray(x, y, scene->camera);
			get_first_intersction(ray, *scene, &color);
			put_pixel(x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->image, 0, 0);
}
