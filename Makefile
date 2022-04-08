NAME = miniRT

CC = gcc


HEADERS = src \
			src/parser \
			src/render \
			src/minilibx-linux \
			src/vector \
			src/ternary_operation \

INCLUDES = $(addprefix -I, $(HEADERS))
LXFLAGS		=	-lXext -lX11 -lm


CFLAGS = -O3 $(INCLUDES) $(LXFLAGS)
# CFLAGS = -O3 -Werror -Wall -Wextra -g -fsanitize=address -Iinclude

SRCS = src/parser/dummy_parse.c \
	src/render/render.c \
	src/render/detect_colision.c \
	src/render/colide_ray_and_objs.c \
	src/vector/vector.c \
	src/vector/vector_operations.c \
	src/vector/vector_debug.c \
	src/ternary_operation/ternary_operation.c\
	src/main.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C src/minilibx-linux
	cp src/minilibx-linux/libmlx_Linux.a ./
	$(CC) -o $(NAME) $(OBJS) libmlx_Linux.a $(CFLAGS)

clean:
	make clean -C src/minilibx-linux || :
	rm -f $(OBJS)

fclean: clean
	make clean -C src/minilibx-linux || :
	rm -f $(NAME)
	rm libmlx.a

re: fclean all
