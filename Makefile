# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 19:18:37 by mmeising          #+#    #+#              #
#    Updated: 2021/10/20 16:51:50 by mmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRCS := so_long.c color_manipulation.c create_get_trgb.c
SRCS := $(SRCS:%=src/%)
OBJ := $(SRCS:src/%.c=obj/%.o)

all: $(NAME)

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $<)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all