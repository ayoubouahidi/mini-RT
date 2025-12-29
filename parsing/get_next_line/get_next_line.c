/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:20:42 by ayouahid          #+#    #+#             */
/*   Updated: 2025/12/29 15:34:10 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

char	*joinfree(char *buff, char *readed)
{
	char	*tmp;

	if (!buff)
		buff = gnl_strdup("");
	tmp = gnl_strjoin(buff, readed);
	free(buff);
	return (tmp);
}

char	*newpointer(char *buff)
{
	int		i;
	char	*newbuff;

	i = 0;
	if (!buff)
		return (NULL);
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\0')
	{
		free(buff);
		return (NULL);
	}
	newbuff = gnl_strdup(buff + i + 1);
	free(buff);
	return (newbuff);
}

char	*get_line(char *buff)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (buff[i] == '\0')
		return (NULL);
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	j = 0;
	while (buff[j] != '\n' && buff[j] != '\0')
	{
		line[j] = buff[j];
		j++;
	}
	if (buff[j] == '\n')
	{
		line[j] = '\n';
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*readfile(int fd, char *buff)
{
	ssize_t	octreaded;
	char	*readed;

	readed = malloc(BUFFER_SIZE + 1);
	if (!readed)
		return (NULL);
	while (1)
	{
		octreaded = read(fd, readed, BUFFER_SIZE);
		if (octreaded <= 0)
			break ;
		readed[octreaded] = '\0';
		buff = joinfree(buff, readed);
		if (gnl_strchr(buff, '\n'))
			break ;
	}
	if (octreaded == -1)
		return (freenull(buff, readed));
	if (octreaded == 0)
	{
		free(readed);
		return (buff);
	}
	free(readed);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = readfile(fd, buff);
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	line = get_line(buff);
	buff = newpointer(buff);
	return (line);
}
