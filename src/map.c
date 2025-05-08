/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:11:45 by ugaudich          #+#    #+#             */
/*   Updated: 2025/04/01 14:11:46 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_map_size(char *file)
{
	int		size;
	int		fd;
	char	*line;

	size = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		size++;
	}
	close(fd);
	if (size == 0)
		exit(EXIT_FAILURE);
	return (size);
}

char	**create_map(char *file)
{
	char	**map;
	int		i;
	int		fd;
	int		size;
	char	*line;

	i = 0;
	size = get_map_size(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

char	**dup_map(char **map)
{
	char	**tmp;
	int		x;
	int		map_size;

	x = 0;
	map_size = get_map_height(map);
	tmp = (char **)malloc(sizeof(char *) * (map_size + 1));
	if (!tmp)
		return (0);
	while (x < map_size)
	{
		tmp[x] = (char *)malloc(sizeof(char) * ft_strlen(map[0]) + 1);
		if (!tmp[x])
			return (0);
		ft_strcpy(tmp[x], map[x]);
		x++;
	}
	tmp[x] = NULL;
	return (tmp);
}

void	spread(char **map, int x, int y)
{
	map[x][y] = '1';
	if (map[x][y + 1] != '1')
		spread(map, x, y + 1);
	if (map[x][y - 1] != '1')
		spread(map, x, y - 1);
	if (map[x + 1][y] != '1')
		spread(map, x + 1, y);
	if (map[x - 1][y] != '1')
		spread(map, x - 1, y);
}

int	is_map_correct(t_game *game, char **map)
{
	char	**tmp_map;

	tmp_map = dup_map(map);
	spread(tmp_map, game->player.y, game->player.x);
	if (!check_spread(tmp_map))
	{
		free_map(tmp_map);
		return (0);
	}
	free_map(tmp_map);
	return (1);
}
