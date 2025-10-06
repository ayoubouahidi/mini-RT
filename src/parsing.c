/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 23:47:50 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/09/12 22:31:45 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../include/minirt.c"
#include "../include/parse.h"
#include "../libft/libft.h"
#include <math.h>

bool	name_of_file(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (ft_strncmp(name + (len - 3), ".rt", 3))
		return (1);
	return (0);
}

bool	valid_file(int ac, char **av)
{
	if (ac != 2 || name_of_file(av[1]))
		return (1);
	return (0);
}

t_coordinates	parse_coordinates(char *coord_str)
{
	t_coordinates	coordinates;
	char			**coord;

	if (ft_count_word(coord_str, ',') != 3)
		exit(1); // handle error
	coord = ft_split(coord_str, ',');
	coordinates.x = ft_atoi_modf(coord[0]);
	coordinates.y = ft_atoi_modf(coord[1]);
	coordinates.z = ft_atoi_modf(coord[2]);
	free(coord[0]);
	free(coord[1]);
	free(coord[2]);
	free(coord);
	return (coordinates);
}

t_color	parse_color(char *color_str)
{
	t_color	color;
	char	**colors;

	if (ft_count_word(color_str, ',') != 3)
		exit(1); // handle error
	colors = ft_split(color_str, ',');
	color.red = ft_atoi(colors[0]);
	color.green = ft_atoi(colors[1]);
	color.blue = ft_atoi(colors[2]);
	free(colors[0]);
	free(colors[1]);
	free(colors[2]);
	free(colors);
	return (color);
}

void	parse_ambient_light(t_token *head_token, t_scene *scene)
{
	t_ambient_light	ambient_light;
	t_token			*token;

	token = head_token;
	if (!token || !token->next || !token->next->next)
		return (error_handler("Invalid ambient light format"));
	// printf("token value in ambient light [%s]\n", token->value);
	ambient_light.id = "A";
	ambient_light.ratio = ft_atoi_modf(token->next->value);
	if (ambient_light.ratio < 0.0 || ambient_light.ratio > 1.0)
		return (error_handler("Ambient light ratio must be between 0.0 and 1.0"));
	ambient_light.color = parse_color(token->next->next->value);
	if (ambient_light.color.red < 0 || ambient_light.color.red > 255
		|| ambient_light.color.green < 0 || ambient_light.color.green > 255
		|| ambient_light.color.blue < 0 || ambient_light.color.blue > 255)
		return (error_handler("Color values must be between 0 and 255"));
	// printf("ambient light ration ==> [%f]\n", ambient_light.ratio);
	// printf("ambient light colors ==> [%f],[%f],[%f]\n",ambient_light.color.red, ambient_light.color.green,ambient_light.color.blue);
	scene->ambient_light = ambient_light;
	// scene++;
}

void	parse_camera(t_token *head_token, t_scene *scene)
{
	t_token		*token;
	t_camera	camera;

	token = head_token;
	if (!token || !token->next || !token->next->next || !token->next->next->next)
		return (error_handler("invalid camera format"));
	camera.id = "C";
	camera.viewpoint = parse_coordinates(head_token->next->value);
	if (camera.viewpoint.x < -50.0 || camera.viewpoint.x > 50.0 ||
		camera.viewpoint.y < -50.0 || camera.viewpoint.y > 50.0 ||
		camera.viewpoint.z < -50.0 || camera.viewpoint.z > 50.0)
		return (error_handler("camera viewpoint coordinates should be in  [-50.0, 50.0]"));
	camera.orientation = parse_coordinates(head_token->next->next->value);
	if (camera.orientation.x < -1.0 || camera.orientation.x > 1.0 ||
		camera.orientation.y < -1.0 || camera.orientation.y > 1.0 ||
		camera.orientation.z < -1.0 || camera.orientation.z > 1.0)
		return (error_handler("camera orientation vector should be in [-1.0, 1.0]"));
	camera.fov = ft_atoi(head_token->next->next->next->value);
	if (camera.fov < 0 || camera.fov > 180)
		return (error_handler("Camera FOV should be in [0, 180] "));
	scene->camera = camera;
}

void	parse_light(t_token *head_token, t_scene *scene)
{
	t_light	light;
	t_light	*tmp_array_light;
	int		i;

	i = 0;
	light.id = "L";
	light.light_point = parse_coordinates(head_token->next->value);
	light.brightness_ratio = ft_atoi_modf(head_token->next->next->value);
	if (light.brightness_ratio < 0.0 || light.brightness_ratio > 1.0)
		return (error_handler("the light brightness ratio should be in the range [0.0,1.0]"));
	light.color = parse_color(head_token->next->next->next->value);
	if (light.color.red < 0 || light.color.red > 255
		|| light.color.green < 0 || light.color.green > 255
		|| light.color.blue < 0 || light.color.blue > 255)
		return (error_handler("Color values must be between 0 and 255"));
	tmp_array_light = malloc(sizeof(t_light) * (scene->num_lights + 1));
	if (!tmp_array_light)
		exit(1);
	while (i < scene->num_lights)
	{
		tmp_array_light[i] = scene->lightes[i];
		i++;
	}
	tmp_array_light[scene->num_lights] = light;
	if (scene->lightes)
		free(scene->lightes);
	scene->lightes = tmp_array_light;
	scene->num_lights++;
}

void	parse_sphere(t_token *head_token, t_scene *scene)
{
	t_sphere	sphere;
	t_sphere	*tmp_array_sphere;
	int			i;

	i = 0;
	sphere.id = "sp";
	sphere.sphere_center = parse_coordinates(head_token->next->value);
	sphere.diameter = ft_atoi_modf(head_token->next->next->value);
	if (sphere.sphere_center.x < -1.0 || sphere.sphere_center.x > 1.0 ||
		sphere.sphere_center.y < -1.0 || sphere.sphere_center.y > 1.0 ||
		sphere.sphere_center.z < -1.0 || sphere.sphere_center.z > 1.0)
		return (error_handler("vector should be in [-1.0, 1.0]"));
	sphere.color = parse_color(head_token->next->next->next->value);
	if (sphere.color.red < 0 || sphere.color.red > 255
		|| sphere.color.green < 0 || sphere.color.green > 255
		|| sphere.color.blue < 0 || sphere.color.blue > 255)
		return (error_handler("Color values must be between 0 and 255"));
	tmp_array_sphere = malloc(sizeof(t_sphere) * (scene->num_sphere + 1));
	if (!tmp_array_sphere)
		exit(1);
	while (i < scene->num_sphere)
	{
		tmp_array_sphere[i] = scene->spheres[i];
		i++;
	}
	tmp_array_sphere[scene->num_sphere] = sphere;
	if (scene->spheres)
		free(scene->spheres);
	scene->spheres = tmp_array_sphere;
	scene->num_sphere++;
}

void	parse_plane(t_token *head_token, t_scene *scene)
{
	t_plane	plane;
	t_plane	*plane_array;
	int		i;

	i = 0;
	plane.id = "pl";
	plane.point_center = parse_coordinates(head_token->next->value);
	plane.normalized_vector = parse_coordinates(head_token->next->next->value);
	plane.color = parse_color(head_token->next->next->next->value);
	plane_array = malloc(sizeof(t_plane) * (scene->num_planes + 1));
	if (!plane_array)
		exit(1);
	while (i < scene->num_planes)
	{
		plane_array[i] = scene->planes[i];
		i++;
	}
	plane_array[scene->num_planes] = plane;
	if (scene->planes)
		free(scene->planes);
	scene->planes = plane_array;
	scene->num_planes++;
}

// void	parse_cylinder(t_token *head_token, t_scene *scene)
// {
// 	t_cylinder	cylinder;
// 	t_cylinder	*cylinder_array;
// }

void	parse_to_scene(char *line, t_scene *scene)
{
	char	*trim;
	t_lexer	*lexer;
	t_token	*token;
	t_token	*head_token;

	head_token = NULL;
	trim = ft_strtrim(line, " ");
	lexer = creat_lexer(trim);
	token = NULL;
	while (1)
	{
		token = tokenize(lexer);
		ft_lstadd_back_token(&head_token, token);
		if (ft_strcmp(token->value, "END") == 0)
			break ;
	}
	// print all the token
	print_linked_list(head_token);
	if (ft_strcmp(head_token->value, "A") == 0)
		parse_ambient_light(head_token, scene);
	if (ft_strcmp(head_token->value, "C") == 0)
		parse_camera(head_token, scene);
	if (ft_strcmp(head_token->value, "L") == 0)
		parse_light(head_token, scene);
	if (ft_strcmp(head_token->value, "sp") == 0)
		parse_sphere(head_token, scene);
	if (ft_strcmp(head_token->value, "pl") == 0)
		parse_plane(head_token, scene);
	// if (ft_strcmp(head_token->value, "cy") == 0)
	// 	parse_cylinder(head_token, scene);
	// printf("ambient light ration ==> [%f]\n", scene->ambient_light.ratio);
	// printf("ambient light colors ==> [%f],[%f],[%f]\n",scene->ambient_light.color.red, scene->ambient_light.color.green,scene->ambient_light.color.blue);
	// printf("CAMERA fov==> [%d]", scene->camera.fov);
}

void	parser_file(char *filename, t_scene *scene)
{
	int		fd;
	int		lines_nums;
	char	*line;

	fd = open(filename, O_RDONLY);
	lines_nums = 0;
	while (1)
	{
		line = get_next_line(fd);
		// printf("test\n");
		if (line == NULL)
			break ;
		lines_nums++;
		if (line[0] == '\0' || line[0] == '\n' || line[0] == '#')
			continue ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		parse_to_scene(line, scene);
	}
	close(fd);
}
