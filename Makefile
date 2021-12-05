# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 19:18:37 by mmeising          #+#    #+#              #
#    Updated: 2021/12/05 17:10:51 by mmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := gcc
CFLAGS := -Wall -Wextra -Werror

SRCS := create_get_trgb.c put_circle.c color_rainbow.c key_hooks.c \
		player_enemy_on_screen.c map_input.c error.c map_init_and_count.c \
		map_tile_size.c list.c img_init.c img_fill.c utilities.c \
		img_colors_list.c img_ex_coll_enemy.c enemy_movement.c so_long.c \
		map_nl.c

SRCS := $(SRCS:%=src/%)
OBJ := $(SRCS:src/%.c=obj/%.o)

LIBFT_NAME := ./libft/lib/libft.a
MLX_NAME := ./mlx/libmlx.a

HEADER := ./header/
LIBFT_HEADER := ./libft/header/
MLX_HEADER := ./mlx/

MLX_FLAGS := -L ./mlx/ -lmlx -framework OpenGL -framework AppKit

HEADER_FLAGS := -I $(HEADER) -I $(LIBFT_HEADER) -I $(MLX_HEADER)
HEADER_FILES := $(HEADER)keys.h $(HEADER)so_long.h

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all: $(NAME)

bonus: all

$(NAME): $(OBJ) $(LIBFT_NAME) $(MLX_NAME)
	$(CC) $(CFLAGS) $(HEADER_FLAGS) $(MLX_FLAGS) $(OBJ) $(LIBFT_NAME) $(MLX_NAME) -o $(NAME)

$(LIBFT_NAME):
	@echo Compiling libft
	@make -C ./libft/
	@printf $(UP)$(CUT)
	@echo Finished compiling libft

$(MLX_NAME):
	@echo Compiling mlx
	@make -C ./mlx/
	@printf $(UP)$(CUT)
	@echo Finished compiling mlx

obj/%.o: src/%.c $(HEADER_FILES)
	@echo Compiling $@
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $<)
	$(CC) $(CFLAGS) $(HEADER_FLAGS) -Imlx -c $< -o $@
	@printf $(UP)$(CUT)
	@echo Finished compiling $@
	@printf $(UP)$(CUT)

clean:
	@echo Cleaning...
	@rm -rf obj/
	@printf $(UP)$(CUT)
	@echo Cleaned!
	@echo Cleaning libft...
	@make -C ./libft/ clean
	@printf $(UP)$(CUT)
	@echo Cleaned libft!

fclean: clean
	@echo Cleaning...
	@rm -f $(NAME)
	@printf $(UP)$(CUT)
	@echo Cleaned!
	@echo Cleaning libft...
	@make -C ./libft/ fclean
	@printf $(UP)$(CUT)
	@echo Cleaned libft!

re: fclean all

.PHONY: all clean fclean re