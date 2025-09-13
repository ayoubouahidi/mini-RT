NAME = mini

CC = cc 
CFLAGS = -Wall -Wextra -Werror -Imlx

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -Iincludes -I$(LIBFT_DIR)

SRCS = gnl/get_next_line.c  gnl/get_next_line_utils.c \
		src/main.c \
		src/parser_utils.c  \
		src/parser.c \
 
OBJS = $(SRCS:%.c=%.o)
# OBJ_DIR = .obj

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

# $(OBJ_DIR):
# 	mkdir .obj

# $(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
# 	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: ${OBJS}
