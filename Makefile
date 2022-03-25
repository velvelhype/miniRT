NAME = miniRT

CC = gcc

CFLAGS = -O3 -Iparser libmlx.dylib
# CFLAGS = -O3 -Werror -Wall -Wextra -g -fsanitize=address -Iinclude
SRCS = src/main.c \
	src/parser/dummy_parse.c \
	src/drawer/draw.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all