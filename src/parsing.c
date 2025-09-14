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
#include "../libft/libft.h"
#include "../include/parse.h"

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


void	parse_ambient_light(t_token *head_token, t_scene *scene)
{
	t_ambient_light ambient_light;
	t_token *token;
	t_color color;
	char **colors;

	token = head_token;
	// printf("token value in ambient light [%s]\n", token->value);
	ambient_light.id = "A";
	ambient_light.ratio = ft_atoi_modf(token->next->value);
	if (ft_count_word(token->next->next->value, ',') != 3)
		exit(1); // handle error maybe i will print an error mssg here or to change a flag
	colors = ft_split(token->next->next->value, ',');
	color.red = ft_atoi(colors[0]);
	color.green = ft_atoi(colors[1]);
	color.blue = ft_atoi(colors[2]);
	ambient_light.color = color;
	// printf("ambient light ration ==> [%f]\n", ambient_light.ratio);
	// printf("ambient light colors ==> [%f],[%f],[%f]\n", ambient_light.color.red, ambient_light.color.green, ambient_light.color.blue);
	scene->ambient_light = ambient_light;
	// scene++;
}

void	parse_camera(t_token *head_token, t_scene *scene)
{
	t_token *token;
	t_camera camera;
	t_coordinates coordinates;
	t_coordinates orientation;
	char **coord;

	token = head_token;
	camera.id = "C";
	if (ft_count_word(token->next->value, ',') != 3 || ft_count_word(token->next->next->value, ',') != 3)
		exit(1); // handle error maybe i will print an error mssg here or to change a flag
	coord = ft_split(head_token->next->value, ','); 
	coordinates.x = ft_atoi_modf(coord[0]);
	coordinates.y = ft_atoi_modf(coord[1]);
	coordinates.z = ft_atoi_modf(coord[2]);
	coord = NULL;
	coord =  ft_split(head_token->next->next->value, ',');
	orientation.x = ft_atoi_modf(coord[0]);
	orientation.y = ft_atoi_modf(coord[1]);
	orientation.z = ft_atoi_modf(coord[2]);
	camera.viewpoint = coordinates;
	camera.orientation = orientation;
	camera.fov = ft_atoi(head_token->next->next->next->value);
	scene->camera = camera;
}

void	parse_to_scene(char *line, t_scene *scene)
{
	char *trim;
	t_lexer *lexer;
	t_token *token;
	t_token *head_token;

	head_token = NULL;
	trim = ft_strtrim(line, " ");
	lexer = creat_lexer(trim);
	token = NULL;
	while (1)
	{
		token = tokenize(lexer);
		ft_lstadd_back_token(&head_token, token);
		if (ft_strcmp(token->value, "END") == 0)
			break;
	}
	// print all the token 
	print_linked_list(head_token);
	if (ft_strcmp(head_token->value, "A") == 0)
		parse_ambient_light(head_token, scene);
	if (ft_strcmp(head_token->value, "C") == 0)
		parse_camera(head_token, scene);
	// if (ft_strcmp(head_token->value, "L") == 0)
	// 	parse_light(head_token, scene);
	// if (ft_strcmp(head_token->value, "sp") == 0)
	// 	parse_light(head_token, scene);	
	// printf("ambient light ration ==> [%f]\n", scene->ambient_light.ratio);
	// printf("ambient light colors ==> [%f],[%f],[%f]\n", scene->ambient_light.color.red, scene->ambient_light.color.green, scene->ambient_light.color.blue);
	// printf("CAMERA fov==> [%d]", scene->camera.fov);
}

void	parser_file(char *filename, t_scene *scene)
{
	int fd;
	int lines_nums;
	char *line;

	fd = open(filename, O_RDONLY);
	lines_nums = 0;
	while (1)
	{
		line = get_next_line(fd);
		// printf("test\n");
		if (line == NULL)
			break;
		lines_nums++;
		if (line[0] == '\0' || line[0] == '\n' || line[0] == '#')
			continue;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		parse_to_scene(line, scene);
	}
	close(fd);
}
