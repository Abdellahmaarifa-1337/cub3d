CC = CC

CFLAGS = -Werror -Wextra -Wall
MLX_OP = -lmlx -framework OpenGL -framework AppKit #-fsanitize=address -g

NAME = cube3D
NAME_BONUS = ../cube3D_bonus

SRC = ./main.c ./parsing/parse_map.c \
		./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
		./render_game/render_game.c ./parsing/get_identifiers.c ./parsing/get_map.c \
		./parsing/utils.c ./parsing/get_map_utils.c ./parsing/get_identifiers_utils.c \
		./parsing/check_if_close.c \
		./manage_player/player_moves.c ./manage_player/player_moves_management.c \
		./render_game/set_vertical_ray.c ./render_game/ray_utils.c ./render_game/set_horizontal_ray.c\
		./manage_player/player_eyesight.c \
		./render_game/render_scene.c ./render_game/get_ray_dist.c ./render_game/texture.c \
		./render_game/utils.c ./render_game/init_game.c

OBJ = ${SRC:.c=.o}

LIB = ./libft/libft.a
MLX_LIB = ./libmlx.a

.c.o :
	@${CC} ${CFLAGS} -Imlx -c $< -o $@
	@echo -n .
all :  mlx_extract  ${NAME}

${NAME} : libft_mk ${OBJ} ${MLX_LIB}
	@${CC} ${CFLAGS} ${OBJ} ${LIB} ${MLX_OP} ${MLX_LIB} -o ${NAME}
	@echo
	@echo "\033[1;32m************* DONE *************\033[0m"
	@echo "run \033[1;32m./${NAME}\033[0m to execute program"
	@echo "\033[1;32m********************************\033[0m"

libft_mk :
	@make -sC ./libft

${MLX_LIB} :
	@make -sC ./mlx

bonus : mlx_extract
	@make -sC ./libft
	@make -sC ./bonus

mlx_extract :
	@tar -xf mlx.tar

clean :
	@make clean -sC ./libft
	@make clean -sC ./bonus
	@rm -rf mlx
	@rm -rf ${OBJ}
	@echo "\033[1;31m************* Removed **************\033[0m"

fclean : clean
	@make fclean -sC ./libft
	@make fclean -sC ./bonus
	@rm -rf ${NAME}
	@rm -rf ${MLX_LIB}

re : fclean all

.PHONY : all clean fclean re
