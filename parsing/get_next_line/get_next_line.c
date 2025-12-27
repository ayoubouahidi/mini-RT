/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:20:42 by ayouahid          #+#    #+#             */
/*   Updated: 2025/12/13 00:29:29 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

char	*joinfree(char *buff, char *readed)
{
	char	*tmp;

	if (!buff)
		buff = gnl_strdup("");
	tmp = gnl_strjoin(buff, readed);
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
		return (NULL);
	newbuff = gnl_strdup(buff + i + 1);
	return (newbuff);
}

char	*pars_line(char *buff)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (buff[i] == '\0')
		return (NULL);
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	line = gc(i + 2);
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

	readed = gc(BUFFER_SIZE + 1);
	octreaded = read(fd, readed, BUFFER_SIZE);
	while (octreaded > 0)
	{
		readed[octreaded] = '\0';
		buff = joinfree(buff, readed);
		if (gnl_strchr(buff, '\n'))
			break ;
		octreaded = read(fd, readed, BUFFER_SIZE);
	}
	if (octreaded == -1)
		return (NULL);
	if (octreaded == 0)
		return (buff);
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
		return (NULL);
	line = pars_line(buff);
	buff = newpointer(buff);
	return (line);
}
