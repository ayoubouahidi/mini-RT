NAME = mini

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

INCLUDES = -Iincludes -I$(LIBFT_DIR)

SRCS = get_next_line/get_next_line.c  get_next_line/get_next_line_utils.c \
		src/main.c \
		src/parser_utils.c  \
		src/parsing.c \
		src/rendring.c \
		src/ray.c \
		src/vectors.c \
		src/hits.c
 
OBJS = $(SRCS:%.c=%.o)
# OBJ_DIR = .obj

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_LIB) -lX11 -lXext -lm

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

$(MLX_LIB):
	make -C $(MLX_DIR)

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
