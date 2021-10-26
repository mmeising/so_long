# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 19:18:37 by mmeising          #+#    #+#              #
#    Updated: 2021/10/26 22:13:03 by mmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRCS := so_long.c create_get_trgb.c put_circle.c mouse_move.c mouse_click.c \
		color_manipulation.c key_hooks.c player_on_screen.c wall.c tst.c
SRCS := $(SRCS:%=src/%)
OBJ := $(SRCS:src/%.c=obj/%.o)
HEADERFILES := src/keys.h src/so_long.h

all: $(NAME)

obj/%.o: src/%.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $<)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

run: all
	./so_long

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all