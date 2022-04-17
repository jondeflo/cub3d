FLAGS = -Wall -Wextra -Werror -I.
NAME = cub3D
HEADER = cub3d.h
SRC = main.c init.c move.c rotate.c handler.c utils.c draw_wall.c draw_sprite.c bitmap.c sprites.c textures.c exit.c \
./parser/get_next_line.c ./parser/get_next_line_utils.c ./parser/parser.c ./parser/config_parser.c ./parser/parser_tools.c \
./parser/ft_is.c ./parser/ft_list.c ./parser/ft_memory.c ./parser/ft_write.c ./parser/ft_split.c ./parser/ft_utils.c \
./parser/string_check.c ./parser/map_parser.c ./parser/map_check.c ./parser/color_parser.c ./parser/parser_utils.c

LIB = ./libmlx/libmlx.a
ARGS = -framework OpenGL -framework AppKit
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libmlx
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) $(ARGS)

mlx:
	$(MAKE) -C ./libmlx

clean:
	/bin/rm -f $(OBJ)
	$(MAKE) clean -C ./libmlx

fclean:	clean
	/bin/rm -f $(NAME)
	/bin/rm -f ./libmlx/libmlx.a

re: fclean all

.PHONY: all clean fclean re
