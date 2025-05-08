/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:10:07 by ugaudich          #+#    #+#             */
/*   Updated: 2024/12/21 16:04:46 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(int fd, char *line, char *buf)
{
	int		bytes_read;

	bytes_read = 1;
	while (ft_strchr(line, '\n') == NULL)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			free(line);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		line = gnl_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*buf;
	static char	*line;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buf);
		return (NULL);
	}
	line = ft_get_line(fd, line, buf);
	if (line == NULL)
	{
		free(line);
		return (NULL);
	}
	tmp = ft_get_rest(line);
	line = trim_prev_line(line);
	return (tmp);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int i = 0;
	int	fd_0 = open("texte.txt", O_RDONLY);
	char *fd;

	while (i < 15)
	{
		fd = get_next_line(fd_0);
		printf("Line n %d : %s\n", i, fd);
		i++;
		free(fd);
	}
	close (fd_0);
	return (0);
}
*/