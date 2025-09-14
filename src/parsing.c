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
	// t_color *color;

	// ambient_light = NULL;
	token = head_token;
	printf("token value in ambient light [%s]\n", token->value);
	ambient_light.id = "A";
	ambient_light.ratio = ft_atoi_modf(token->next->value);
	printf("ambient light ration ==> [%f]", ambient_light.ratio);
	// ambient_light->color = 
	scene++;
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
