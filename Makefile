NAME = mini

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -Imlx


SRCS =  src/main.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJ_DIR = .obj

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

$(OBJ_DIR):
	mkdir .obj

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -rf .obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: ${OBJS}