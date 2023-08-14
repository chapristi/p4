FILES = ./srcs/game_status.c ./srcs/game.c ./srcs/main.c ./srcs/player.c
OBJ = ${FILES:.c=.o}
HSRCS = includes/
CC = gcc
CFLAGS =-Wall -Wextra -Werror
BIN = main

all: ${BIN}
     
${BIN}: ${OBJ}
    ${CC} ${FILES} ${CFLAGS} -I ${HSRCS} -o $@

%.o : %.c
    ${CC} -c $^ $(CFLAGS) -o $@

clean:
    rm ${OBJ}

fclean: ${OBJ}
    rm ${BIN}

re: fclean all

.PHONY: all clean fclean re