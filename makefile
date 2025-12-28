SRC = \
\
src/main.c \
src/get_mlx.c \
src/make_image.c \
\
garbage_collecter/gc_create.c \
\
parsing/parsing.c \
parsing/parsing_utils.c \
parsing/pars_a_light.c \
parsing/pars_camera.c \
parsing/pars_cylinder.c \
parsing/pars_light.c \
parsing/pars_palne.c \
parsing/pars_sphere.c \
parsing/get_next_line/get_next_line.c \
parsing/get_next_line/get_next_line_utils.c \
\
math/color.c \
math/cylinder_intersction.c \
math/light_intersection.c \
math/plane_intersction.c \
math/screen.c \
math/sphere_intersction.c \
math/tuple.c \
math/tuple1.c \
\
lib/ft_atof.c \
lib/ft_atoi.c \
lib/ft_bzero.c \
lib/ft_calloc.c \
lib/ft_isalnum.c \
lib/ft_isalpha.c \
lib/ft_isascii.c \
lib/ft_isdigit.c \
lib/ft_isprint.c \
lib/ft_itoa.c \
lib/ft_lstadd_back_bonus.c \
lib/ft_lstadd_front_bonus.c \
lib/ft_lstclear_bonus.c \
lib/ft_lstdelone_bonus.c \
lib/ft_lstiter_bonus.c \
lib/ft_lstlast_bonus.c \
lib/ft_lstmap_bonus.c \
lib/ft_lstnew_bonus.c \
lib/ft_lstsize_bonus.c \
lib/ft_memchr.c \
lib/ft_memcmp.c \
lib/ft_memcpy.c \
lib/ft_memmove.c \
lib/ft_memset.c \
lib/ft_putchar_fd.c \
lib/ft_putendl_fd.c \
lib/ft_putnbr_fd.c \
lib/ft_putstr_fd.c \
lib/ft_split.c \
lib/ft_strchr.c \
lib/ft_strdup.c \
lib/ft_striteri.c \
lib/ft_strjoin.c \
lib/ft_strlcat.c \
lib/ft_strlcpy.c \
lib/ft_strlen.c \
lib/ft_strmapi.c \
lib/ft_strncmp.c \
lib/ft_strnstr.c \
lib/ft_strrchr.c \
lib/ft_strtrim.c \
lib/ft_substr.c \
lib/ft_tolower.c \
lib/ft_toupper.c

CC = cc

CF = -Wall -Wextra -Werror

all :
	$(CC) $(CF) $(SRC) -march=native -ffast-math -ftree-vectorize -funroll-loops -flto -fno-signed-zeros	-lmlx -lXext -lX11 -lm -o miniRT #-fsanitize=address -g3

#clean :
#	rm $(SRC%.c=.o)

fclean :
	rm miniRT
