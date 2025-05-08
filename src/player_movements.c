/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:21:39 by ugaudich          #+#    #+#             */
/*   Updated: 2025/04/07 12:21:40 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_player(t_game *game, int new_x, int new_y)
{
	int	exit_check;

	exit_check = (game->map[new_y][new_x] == 'D');
	if (game->map[new_y][new_x] == '1')
		return (0);
	if (exit_check && game->player.collectibles == game->nb_collectibles)
	{
		ft_printf("Well done, you completed the level in %d moves !\n",
			game->player.moves + 1);
		close_game(game);
		exit(0);
	}
	if (game->map[new_y][new_x] == 'C')
		game->player.collectibles++;
	update_previous_pos(game);
	game->player.x = new_x;
	game->player.y = new_y;
	game->player.moves++;
	game->map[game->player.y][game->player.x] = 'P';
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	ft_printf("moves: %d\n", game->player.moves);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	if (keycode == 119 || keycode == 65362)
		move_player(game, game->player.x, game->player.y - 1);
	if (keycode == 115 || keycode == 65364)
		move_player(game, game->player.x, game->player.y + 1);
	if (keycode == 97 || keycode == 65361)
		move_player(game, game->player.x - 1, game->player.y);
	if (keycode == 100 || keycode == 65363)
		move_player(game, game->player.x + 1, game->player.y);
	return (0);
}

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_collectible);
	mlx_destroy_image(game->mlx, game->img_end);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_window(game->mlx, game->win);
	free_map(game->map);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

void	update_previous_pos(t_game *game)
{
	if (game->player.y == game->end_y && game->player.x == game->end_x)
		game->map[game->player.y][game->player.x] = 'E';
	else
		game->map[game->player.y][game->player.x] = '0';
	if (game->player.collectibles == game->nb_collectibles)
		game->map[game->end_y][game->end_x] = 'D';
}
