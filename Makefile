mCC = CC

#---------- Flags ??????? 
CFLAGS = -O3 #-Werror -Wextra -Wall
MLX_OP = -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g
#---------- Sanitize ????

NAME = cube3D

SRC = ./main.c ./parsing/parse_map.c handel_error/throw_error.c ./lib/helpers.c \
		./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
		./render_game/render_game.c ./parsing/get_identifiers.c ./parsing/get_map.c \
		./parsing/utils.c ./parsing/get_map_utils.c ./parsing/get_identifiers_utils.c \
		./parsing/check_if_close.c ./temp_functions.c render_game/miniMap.c \
		./manage_player/player_moves.c ./manage_player/player_moves_management.c \
		./render_game/set_vertical_ray.c ./render_game/ray_utils.c ./render_game/set_horizontal_ray.c\
		./manage_player/player_eyesight.c ./manage_player/mouse_hook.c ./render_game/set_rays.c \
		./render_game/render_scene.c ./render_game/get_ray_dist.c ./render_game/texture.c

OBJ = ${SRC:.c=.o}

LIB = ./libft/libft.a
MLX_LIB = ./mlx/libmlx.a

.c.o :
	@${CC} ${CFLAGS} -Imlx -c $< -o $@
	@echo -n .
all: ${NAME}

${NAME} : ${OBJ} ${LIB} ${MLX_LIB}
	@${CC} ${CFLAGS} ${OBJ} ${LIB} ${MLX_OP} ${MLX_LIB} -o ${NAME}
	@echo
	@echo "\033[1;32m************* DONE *************\033[0m"
	@echo "run \033[1;32m./${NAME}\033[0m to execute program"
	@echo "\033[1;32m********************************\033[0m"

${LIB} :
	@make -sC ./libft
	@echo -n .

${MLX_LIB} :
	@make -sC ./mlx
	@echo .

clean:
	@make clean -sC ./libft
	@make clean -sC ./mlx
	@rm -rf ${OBJ}
	@echo "\033[1;31m************* Removed **************\033[0m"

fclean: clean
	@make fclean -sC ./libft
	@rm -rf ${NAME}
	@rm -rf ${MLX_LIB}

re: fclean all

.PHONY: all clean fclean



