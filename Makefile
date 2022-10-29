mCC = CC
CFLAGS = -Werror -Wextra -Wall
NAME = cube3d

SRC = ./main.c ./parsing/parse_map.c handel_error/throw_error.c \
		./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
		./render_game/render_game.c ./parsing/get_identifiers.c ./parsing/get_map.c \
		./parsing/utils.c ./parsing/get_map_utils.c ./parsing/get_identifiers_utils.c \
		./parsing/check_if_close.c ./temp_functions.c render_game/miniMap.c \
		./manage_player/player_moves.c ./manage_player/player_moves_management.c \
		./render_game/set_vertical_ray.c ./render_game/ray_utils.c ./render_game/set_horizontal_ray.c\
		./manage_player/player_eyesight.c ./manage_player/mouse_hook.c

OBJ = ${SRC:.c=.o}

LIB = ./libft/libft.a

.c.o :
	${CC} ${CFLAGS} -Imlx -c $< -o $@

all: ${NAME}

${NAME} : ${OBJ} ${LIB}
		${CC} -g ${CFLAGS} ${OBJ} ${LIB} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

${LIB} :
		make -C ./libft

clean:
	make clean -C ./libft
	rm -rf ${OBJ}

fclean: clean
	make fclean -C ./libft
	rm -rf ${NAME}
re: fclean all

.PHONY: all clean fclean



