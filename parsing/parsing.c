/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:34:47 by hamel-yo          #+#    #+#             */
/*   Updated: 2026/01/04 03:39:58 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"

t_list	*pars_map(int fd)
{
	t_list	*list;
	t_list	*node;
	char	*line;
	char	**splited_line;

	list = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		splited_line = ft_split(line, ' ');
		free(line);
		node = ft_lstnew(splited_line);
		ft_lstadd_back(&list, node);
	}
	return (list);
}

void	pars_list(t_scene *scene, t_list *list)
{
	char	*s;

	while (list)
	{
		s = ((char **)list->content)[0];
		if (*s == '\n' || !ft_strncmp("#", (const char *)s, 1))
			s = "";
		else if (!ft_strncmp("C", (const char *)s, 1))
			scene->camera = pars_camera((char **)list->content);
		else if (!ft_strncmp("L", (const char *)s, 1))
			pars_light(&(scene->light), (char **)list->content);
		else if (!ft_strncmp("A", (const char *)s, 1))
			scene->ambient_light = pars_a_light((char **)list->content);
		else if (!ft_strncmp("sp", (const char *)s, 2))
			pars_sphere(&(scene->sphere), (char **)list->content);
		else if (!ft_strncmp("pl", (const char *)s, 2))
			pars_plane(&(scene->plane), (char **)list->content);
		else if (!ft_strncmp("cy", (const char *)s, 2))
			pars_cylinder(&(scene->cylinder), (char **)list->content);
		else
			parsing_error("error on the object name\n");
		list = list->next;
	}
}

t_scene	parsing(t_list	*list)
{
	static t_scene	scene;

	if (list == NULL)
		return (scene);
	pars_list(&scene, list);
	return (scene);
}

t_scene	pars_scene(int c, char **av)
{
	int		len;
	t_scene	scene;
	int		fd;
	t_list	*list;

	if (c != 2)
		parsing_error("error in the number of the argemnts\n");
	len = ft_strlen(av[1]);
	if (ft_strncmp(".rt", av[1] + (len - 3), 3) != 0)
		parsing_error("error on the file name\n");
	fd = open(av[1], O_RDWR);
	list = pars_map(fd);
	if (list == NULL)
	{
		close(fd);
		parsing_error("empty file\n");
	}
	scene = parsing(list);
	ft_lstclear(&list, free);
	close(fd);
	return (scene);
}
