/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:10:30 by ugaudich          #+#    #+#             */
/*   Updated: 2024/12/05 12:50:17 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	if (c == '\0')
		return (str + gnl_strlen(str));
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == c)
		return (str + i);
	return (NULL);
}

char	*gnl_strjoin(char *line, char *buf)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	if (line == NULL)
	{
		line = malloc(sizeof(char) * 1);
		line[0] = '\0';
	}
	new_line = malloc(sizeof(char) * (gnl_strlen(line) + gnl_strlen(buf)) + 1);
	if (new_line == NULL)
		return (NULL);
	while (line[i] != '\0')
	{
		new_line[i] = line[i];
		i++;
	}
	while (buf[j] != '\0')
		new_line[i++] = buf[j++];
	new_line[i] = '\0';
	free(line);
	return (new_line);
}

char	*ft_get_rest(char *line)
{
	int		i;
	char	*new_line;

	i = 0;
	if (line[i] == '\0' || line == NULL)
		return (NULL);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	new_line = malloc(sizeof(char) * (i + 2));
	if (new_line == NULL)
		return (NULL);
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		new_line[i] = '\0';
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*trim_prev_line(char *line)
{
	int		i;
	int		j;
	char	*f_line;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	f_line = malloc(sizeof(char) * (gnl_strlen(line) - i + 1));
	if (!f_line)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		f_line[j++] = line[i++];
	f_line[j] = '\0';
	free(line);
	return (f_line);
}
