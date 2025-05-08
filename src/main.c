/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:01:20 by ugaudich          #+#    #+#             */
/*   Updated: 2025/02/06 13:01:22 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("Error\nUsage: ./so_long map.ber");
		return (1);
	}
	if (!format_checker(av[1], ".ber"))
	{
		ft_printf("Error\nInvalid file extension. Must be .ber");
		return (1);
	}
	init_game_null(&game);
	if (!init_game(&game, av[1]))
	{
		ft_printf("Failed to initialize game, or ivalid map\n");
		return (1);
	}
	draw_map(&game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win, 17, 1L << 17, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
