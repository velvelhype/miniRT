NAME = miniRT

CC = gcc

CFLAGS = -O3 -Iinclude
# CFLAGS = -O3 -Werror -Wall -Wextra -g -fsanitize=address -Iinclude
SRCS = src/main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all