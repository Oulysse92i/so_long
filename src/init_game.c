/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:08:51 by ugaudich          #+#    #+#             */
/*   Updated: 2025/04/08 22:08:55 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game_null(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->img_floor = NULL;
	game->img_wall = NULL;
	game->img_player = NULL;
	game->img_collectible = NULL;
	game->img_end = NULL;
	game->img_exit = NULL;
	game->player.x = 0;
	game->player.y = 0;
	game->player.moves = 0;
	game->player.collectibles = 0;
	game->width = 0;
	game->height = 0;
	game->img_width = 0;
	game->img_height = 0;
	game->nb_collectibles = 0;
	game->end_x = 0;
	game->end_y = 0;
}

void	init_player_pos(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (game->map[++x])
	{
		y = -1;
		while (game->map[x][++y])
		{
			if (game->map[x][y] == 'P')
			{
				game->player.x = y;
				game->player.y = x;
				game->player.collectibles = 0;
				game->player.moves = 0;
				return ;
			}
		}
	}
}

void	count_collectibles(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	game->nb_collectibles = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'C')
				game->nb_collectibles++;
			y++;
		}
		x++;
	}
}

void	init_exit_pos(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (game->map[++x])
	{
		y = -1;
		while (game->map[x][++y])
		{
			if (game->map[x][y] == 'E')
			{
				game->end_x = y;
				game->end_y = x;
				return ;
			}
		}
	}
}
