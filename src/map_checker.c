/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:32:17 by ugaudich          #+#    #+#             */
/*   Updated: 2025/04/01 13:32:19 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_map_rectangular(char *file)
{
	char	*line;
	int		first_size;
	int		fd;
	int		cur_size;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	first_size = ft_special_strlen(line);
	while (line)
	{
		cur_size = ft_special_strlen(line);
		free(line);
		if (cur_size != first_size)
		{
			close(fd);
			return (0);
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	check_walls(char **map)
{
	int		i;
	int		height;
	int		width;

	height = 0;
	if (!map)
		return (0);
	while (map[height])
		height++;
	width = ft_strlen(map[0]);
	i = -1;
	while (++i < width - 1)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
	}
	i = -1;
	while (++i < height - 1)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
	}
	return (1);
}

int	check_squares(char **map, int start, int exit, int item)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				start++;
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'C')
				item++;
			else if (map[i][j] != '0' && map[i][j] != '1')
				return (0);
		}
	}
	if (start != 1 || exit != 1 || item < 1)
		return (0);
	return (1);
}

int	format_checker(char *file, char *extension)
{
	int	file_len;
	int	extension_len;

	file_len = ft_strlen(file);
	extension_len = ft_strlen(extension);
	if (file_len <= extension_len)
		return (0);
	return (ft_strncmp(&file[file_len - extension_len],
			extension, extension_len + 1) == 0);
}

int	check_spread(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] != '1' && map[x][y] != '0')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
