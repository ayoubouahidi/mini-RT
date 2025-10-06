#include <stdio.h>
// #include "minilibx-linux/mlx.h"
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include <stdlib.h>

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
	t_coordinates point_center;
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


// some structs gonna help me building parser part

typedef struct s_lexer
{
	char			c;
	unsigned int	i;
	char			*content;
}					t_lexer;


typedef struct s_token
{
	char *value;
	struct s_token *next;
}	t_token;

// functions

bool	valid_file(int ac, char **av);
void	parser_file(char *filename, t_scene *scene);
t_token	*tokenize(t_lexer *lexer);
void	ft_lstadd_back_token(t_token **lst, t_token *new);
int 	ft_strcmp(const char *s1, const char *s2);
void	print_linked_list(t_token *head_token);
t_lexer	*creat_lexer(char *content);
double	check_calcul(char *str, int i);
double	ft_atoi_modf(char *str);
size_t	ft_count_word(char *s, char c);
void	error_handler(char *message);