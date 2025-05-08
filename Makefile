# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugaudich <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 12:47:14 by ugaudich          #+#    #+#              #
#    Updated: 2025/02/06 12:47:16 by ugaudich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
MLX_FLAGS = minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm

LIBFT_DIR = src/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
FILES = game_structure.c \
init_game.c \
main.c \
map_checker.c \
map_utils.c \
map.c \
player_movements.c

SRC = $(addprefix $(SRC_DIR)/,$(FILES)) 

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

MLX_DIR = minilibx-linux
MLX = -L$(MLX_DIR)/libmlx_Linux.a

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(FILES:%.c=%.o))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I/include -Iminilibx-linux -O3 -c $< -o $@

$(NAME): $(OBJ)	$(MLX) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(MLX):
	@make -C $(MLX_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean

re:	fclean $(NAME)

.PHONY: all clean fclean re
