# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 14:34:50 by seonchoi          #+#    #+#              #
#    Updated: 2021/07/06 18:22:37 by seonchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
MLXPATH = ./minilibx
CC = gcc
CLFLAGS = -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
SRC =	main.c \
		./src/description.c ./src/description1.c ./src/description2.c \
		./src/key.c ./src/key1.c ./src/floar_ceiling.c ./src/map_checker.c \
		./src/load_image.c ./src/raycasting.c ./src/map_player.c ./src/memory.c \
		./src/libft1.c ./src/libft2.c ./src/libft3.c \
		./src/map_checker_utils.c ./src/free_memory.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): 
		@$(CC) $(FLAGS) -o $(NAME) -L $(MLXPATH) $(CLFLAGS) $(GNL) $(SRC)

clean :
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
