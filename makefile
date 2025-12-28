SRC = */*.c	parsing/get_next_line/*.c

CC = cc

CF = -Wall -Wextra -Werror

all :
	$(CC) $(CF) $(SRC) -march=native -ffast-math -ftree-vectorize -funroll-loops -flto -fno-signed-zeros	-lmlx -lXext -lX11 -lm -o miniRT -fsanitize=address -g3

#clean :
#	rm $(SRC%.c=.o)

fclean :
	rm miniRT
