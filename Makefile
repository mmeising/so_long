# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 19:18:37 by mmeising          #+#    #+#              #
#    Updated: 2021/11/16 21:44:31 by mmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := gcc
CFLAGS := -Wall -Wextra -Werror

SRCS := so_long.c create_get_trgb.c put_circle.c mouse_click.c \
		color_manipulation.c key_hooks.c player_on_screen.c wall.c tst.c \
		map_input.c error.c map_init_and_count.c map_tile_size.c list.c \
		create_colors.c

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


$(NAME): $(OBJ) $(LIBFT_NAME) $(MLX_NAME)
	$(CC) $(CFLAGS) $(HEADER_FLAGS) $(MLX_FLAGS) $(OBJ) $(LIBFT_NAME) $(MLX_NAME) -o $(NAME)

$(LIBFT_NAME):
	@echo Compiling libft
	@make -C ./libft/
	@printf $(UP)$(CUT)
	@echo Finished compiling mlx

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

run: all
	./so_long

clean:
	@echo Cleaning...
	@rm -rf obj/
	@printf $(UP)$(CUT)
	@echo Cleaned!

fclean: clean
	@echo Cleaning...
	@rm -f $(NAME)
	@printf $(UP)$(CUT)
	@echo Cleaned!

re: fclean all

.PHONY: all clean fclean re