CC = CC
CFLAGS = -Werror -Wextra -Wall
NAME = cube3d

SRC = ./main.c ./parssing/parse_map.c handel_error/throw_error.c \
		./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
OBJ = ${SRC:.c=.o} 
LIB = ./libft/libft.a

.c.o :
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME} : ${OBJ} ${LIB}
		${CC} ${CFLAGS} ${OBJ} ${LIB} -o ${NAME}

${LIB} :
		make -C ./libft
${OBJ}: ${SRC}

clean:
	make clean -C ./libft
	rm -rf ${OBJ}

fclean: clean
	make fclean -C ./libft
	rm -rf ${NAME}
re: fclean all

.PHONY: all clean fclean



