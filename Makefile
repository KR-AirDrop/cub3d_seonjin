MMSPATH = ./minilibx
CLFLAGS = -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
LIBFT = ./libft/ft_isdigit.c ./libft/ft_strjoin.c ./libft/ft_strlen.c ./libft/ft_substr.c ./libft/ft_split.c
SRC = ./src/load_image.c ./src/raycasting.c ./src/description.c ./src/description1.c ./src/description2.c  ./src/key.c ./src/key1.c ./src/floar_ceiling.c ./src/map_checker.c ./src/map_player.c  ./src/memory.c
a.out : 
	gcc $(FLAGS) -L $(MMSPATH) $(CLFLAGS) $(GNL) $(LIBFT) $(SRC) main.c

clean :
	rm -rf a.out
