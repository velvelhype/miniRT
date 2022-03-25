NAME = miniRT

CC = gcc

CFLAGS = -O3 -Isrc/parser -Isrc/drawer -Isrc/minilibx \
		-Isrc \
# CFLAGS = -O3 -Werror -Wall -Wextra -g -fsanitize=address -Iinclude
SRCS = src/main.c \
	src/parser/dummy_parse.c \
	src/drawer/draw.c \

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