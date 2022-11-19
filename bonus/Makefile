CC = CC

CFLAGS = -Werror -Wextra -Wall
MLX_OP = -lmlx -framework OpenGL -framework AppKit #-fsanitize=address -g

CUB = cube3D_bonus
NAME = ../${CUB}

SRC = ./main_bonus.c ./parsing/parse_map_bonus.c \
		./get_next_line/get_next_line_bonus.c ./get_next_line/get_next_line_utils_bonus.c \
		./render_game/render_game_bonus.c ./parsing/get_identifiers_bonus.c ./parsing/get_map_bonus.c \
		./parsing/utils_bonus.c ./parsing/get_map_utils_bonus.c ./parsing/get_identifiers_utils_bonus.c \
		./parsing/check_if_close_bonus.c ./manage_player/mouse_hook_bonus.c\
		./manage_player/player_moves_bonus.c ./manage_player/player_moves_management_bonus.c \
		./render_game/set_vertical_ray_bonus.c ./render_game/ray_utils_bonus.c ./render_game/set_horizontal_ray_bonus.c\
		./manage_player/player_eyesight_bonus.c \
		./render_game/render_scene_bonus.c ./render_game/get_ray_dist_bonus.c ./render_game/texture_bonus.c \
		./render_game/utils1_bonus.c ./render_game/utils2_bonus.c \
		./render_game/init_game_bonus.c ./render_game/miniMap_bonus.c

OBJ = ${SRC:.c=.o}

LIB = ../libft/libft.a
MLX_LIB = ../libmlx.a

.c.o :
	${CC} ${CFLAGS} -I../mlx -c $< -o $@
	@echo -n .

all: ${NAME}

${NAME} : libft_mk ${OBJ} ${MLX_LIB}
	${CC} ${CFLAGS} ${OBJ} ${LIB} ${MLX_OP} ${MLX_LIB} -o ${NAME}
	@echo
	@echo "\033[1;32m**************** DONE ****************\033[0m"
	@echo "run \033[1;32m./${CUB}\033[0m to execute program"
	@echo "\033[1;32m**************************************\033[0m"

libft_mk :
	@make -sC ../libft

${MLX_LIB} :
	@make -sC ../mlx

clean:
	@rm -rf ${OBJ}
	@rm -rf mlx

fclean: clean
	@rm -rf ${NAME}
	@rm -rf ${MLX_LIB}

.PHONY: all clean fclean



