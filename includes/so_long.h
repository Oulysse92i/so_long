/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:59:46 by ugaudich          #+#    #+#             */
/*   Updated: 2025/02/06 12:59:48 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../src/libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
	int		collectibles;
}				t_player;

typedef struct s_game
{
	void		*win;
	void		*mlx;
	char		**map;
	int			height;
	int			width;
	int			end_x;
	int			end_y;
	t_player	player;
	int			nb_collectibles;
	void		*img_wall;
	void		*img_floor;
	void		*img_collectible;
	void		*img_end;
	void		*img_player;
	void		*img_exit;
	int			img_width;
	int			img_height;
}				t_game;

////////////////////map parsing////////////////////

int		is_map_rectangular(char *file);
int		check_walls(char **map);
int		check_squares(char **map, int start, int exit, int item);
int		format_checker(char *file, char *extension);
int		is_map_correct(t_game *game, char **map);
void	spread(char **map, int x, int y);
int		check_spread(char **map);

////////////////////////map////////////////////////

int		get_map_size(char *file);
int		get_map_height(char **map);
int		get_map_width(char **map);
char	**create_map(char *file);
void	free_map(char **tab);
char	**dup_map(char **map);

/////////////////////init game/////////////////////

void	init_player_pos(t_game *game);
void	count_collectibles(t_game *game);
int		init_game(t_game *game, char *file);
void	init_exit_pos(t_game *game);
void	init_game_null(t_game *game);

////////////////////////img////////////////////////

void	*img_to_window(t_game *game, char *path);
int		load_textures(t_game *game);
void	display_image_to_window(t_game *game, void *img_ptr, int x, int y);
void	draw_map(t_game *game);

///////////////////////utils///////////////////////

int		ft_special_strlen(char *str);
int		close_game(t_game *game);

//////////////////////player///////////////////////

int		key_hook(int keycode, t_game *game);
void	update_previous_pos(t_game *game);
int		move_player(t_game *game, int new_x, int new_y);

#endif
