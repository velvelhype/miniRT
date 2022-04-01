NAME = miniRT

CC = gcc

CFLAGS = -O3 \
		-Isrc -Isrc/parser -Isrc/render -Isrc/minilibx \
		-Isrc/vector -Isrc/ternary_operation\
# CFLAGS = -O3 -Werror -Wall -Wextra -g -fsanitize=address -Iinclude

SRCS = src/main.c \
	src/parser/dummy_parse.c \
	src/render/render.c \
	src/render/detect_colision.c \
	src/render/colide_ray_and_objs.c \
	src/vector/vector.c \
	src/vector/vector_operations.c \
	src/vector/vector_debug.c \
	src/ternary_operation/ternary_operation.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C src/minilibx
	cp src/minilibx/libmlx.dylib ./
	$(CC) $(CFLAGS) $(OBJS)  libmlx.dylib -o $(NAME)

clean:
	make clean -C src/minilibx || :
	rm -f $(OBJS)

fclean: clean
	make clean -C src/minilibx || :
	rm -f $(NAME)
	rm libmlx.dylib

re: fclean all