/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:40:24 by ugaudich          #+#    #+#             */
/*   Updated: 2025/04/02 14:40:25 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_game(t_game *game, char *file)
{
	game->map = create_map(file);
	if (!game->map)
		return (0);
	game->height = get_map_height(game->map);
	game->width = get_map_width(game->map);
	init_player_pos(game);
	init_exit_pos(game);
	if (!is_map_rectangular(file) || !check_walls(game->map)
		|| !check_squares(game->map, 0, 0, 0)
		|| !is_map_correct(game, game->map))
	{
		free_map(game->map);
		return (0);
	}
	count_collectibles(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, game->width * 64,
			game->height * 64, "so_long");
	if (!game->win)
		return (0);
	if (!load_textures(game))
		return (0);
	return (1);
}

void	*img_to_window(t_game *game, char *path)
{
	void	*img;

	game->img_width = 64;
	game->img_height = 64;
	img = mlx_xpm_file_to_image(game->mlx, path,
			&game->img_width, &game->img_height);
	return (img);
}

int	load_textures(t_game *game)
{
	game->img_floor = img_to_window(game, "textures/floor.xpm");
	game->img_collectible = img_to_window(game, "textures/collectible.xpm");
	game->img_wall = img_to_window(game, "textures/wall.xpm");
	game->img_player = img_to_window(game, "textures/player.xpm");
	game->img_end = img_to_window(game, "textures/exit.xpm");
	game->img_exit = img_to_window(game, "textures/new_exit.xpm");
	if (!game->img_floor || !game->img_collectible || !game->img_wall
		|| !game->img_player || !game->img_end)
		return (0);
	return (1);
}

void	display_image_to_window(t_game *game, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img_ptr, x * 64, y * 64);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (game->map[++x])
	{
		y = -1;
		while (game->map[x][++y])
		{
			display_image_to_window(game, game->img_floor, y, x);
			if (game->map[x][y] == '1')
				display_image_to_window(game, game->img_wall, y, x);
			else if (game->map[x][y] == 'C')
				display_image_to_window(game, game->img_collectible, y, x);
			else if (game->map[x][y] == 'E')
				display_image_to_window(game, game->img_end, y, x);
			else if (game->map[x][y] == 'D')
				display_image_to_window(game, game->img_exit, y, x);
			else if (game->map[x][y] == 'P')
				display_image_to_window(game, game->img_player, y, x);
		}
	}
}
