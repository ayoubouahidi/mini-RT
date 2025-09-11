#include <stdio.h>
#include "minilibx-linux/mlx.h"

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
}		t_color;

typedef struct s_coordinates 
{
	double x;
	double y;
	double z;
}		t_coordinates;

typedef struct s_ambient_light
{
	char 	*id;
	double	ratio;
	t_color color;
}		t_ambient_light;

typedef struct s_camera
{
	char	*id;
	t_coordinates	viewpoint;
	t_coordinates	orientation;
	int fov;
}		t_camera;

typedef	struct	s_light 
{
	char		*id;
	t_coordinates	light_point;
	double	 brightness_ratio;
	t_color color;
}		t_light;

typedef struct s_sphere
{
	char	*id;
	t_coordinates	sphere_center;
	double	diameter;
	double	radius;
	t_color color;
}		t_sphere;

typedef struct s_plane
{
	char *id;
	t_coordinates point;
	t_coordinates normalized_vector;
	t_color color;
}		t_plane;

typedef struct	s_cylinder
{
	char	*id;
	t_coordinates center_cylinder;
	t_coordinates normalized_vector;
	int diameter;
	int	height;
	t_color color;
}		t_cylinder;

typedef struct s_scene
{
	void				*mlx;
	void				*mlx_win;
	t_ambient_light		ambient_light;
	t_camera	camera;
	t_light *lightes;
	t_sphere *spheres;
	t_plane	*planes;
	t_cylinder *cylinders;
	int	num_lights;
	int	num_sphere;
	int num_planes;
	int num_cylinder;
}		t_scene;
