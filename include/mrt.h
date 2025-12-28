/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:13:33 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/21 09:18:29 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_H
# define MRT_H

# include <stdbool.h>
# include "parse.h"
# include "gc.h"
# include "libft.h"
# include <mlx.h>
# include <math.h>
# include "math.h"
# include "print.h"
# include <float.h>

# define WIDTH 1900
# define HEIGHT 1080

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*image;
	void	*addr;
	int		bpp;
	int		s_line;
	int		endian;
}	t_mlx;

double	sp_in(t_ray ray, t_sphere sp);
t_ray	get_ray(t_ushort x, t_ushort y, t_camera camera);
void	put_imageonwindow(t_scene *scene, char *f_name);
void	print_coordinate(t_tuple coor);
#endif
