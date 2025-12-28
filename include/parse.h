/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:45:50 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/12/28 20:23:49 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdbool.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "gc.h"

typedef unsigned char	t_uchar;
typedef unsigned short	t_ushort;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}		t_color;

typedef struct s_coordinates
{
	double	x;
	double	y;
	double	z;
	double	v;
}		t_tuple;

typedef struct s_ambient_light
{
	double	ratio;
	t_color	color;
}		t_ambient_light;

typedef struct s_camera
{
	t_tuple	forward;
	t_tuple	viewpoint;
	double	fov;
}		t_camera;

typedef struct s_light
{
	t_tuple			point;
	double			b_ratio;
	t_color			color;
	struct s_light	*next;
}		t_light;

typedef struct s_sphere
{
	t_tuple			center;
	double			rad_square;
	t_color			color;
	struct s_sphere	*next;
}		t_sphere;

typedef struct s_plane
{
	t_tuple			point;
	t_tuple			n_vector;
	t_color			color;
	struct s_plane	*next;
}		t_plane;

typedef struct s_cylinder
{
	t_tuple				center;
	t_tuple				n_vector;
	double				diameter;
	double				rad_square;
	double				height;
	t_color				color;
	struct s_cylinder	*next;
}		t_cylinder;

typedef struct s_scene
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_ambient_light		ambient_light;
	t_camera			camera;
	t_light				*light;
	t_sphere			*sphere;
	t_plane				*plane;
	t_cylinder			*cylinder;
	int					num_light;
	int					num_sphere;
	int					num_planes;
	int					num_cylinder;
}		t_scene;

t_scene				pars_scene(int c, char **av);
t_ambient_light		pars_a_light(char **args);
t_camera			pars_camera(char **args);
void				pars_cylinder(t_cylinder **cylinder, char **args);
void				pars_light(t_light **light, char **args);
void				pars_plane(t_plane **plane, char **args);
void				pars_sphere(t_sphere **sphere, char **args);
t_color				pars_color(char *s);
double				pars_ratio(char *s);
t_tuple				pars_coordinate(char *s, bool v);
t_tuple				pars_vector(char *s);

#endif
