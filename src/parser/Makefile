NAME = libparser.a

CC = gcc

HEADERS = ../ \
			../libft \
			../vector \
			../ternary_operation \

INCLUDES = $(addprefix -I, $(HEADERS))
LXFLAGS		=	-lXext -lX11 -lm


CFLAGS = -O3 $(INCLUDES) $(LXFLAGS) -g
# CFLAGS = -O3 -Werror -Wall -Wextra -g -fsanitize=address -Iinclude

SRCS = get_next_line.c \
		dummy_parse.c \
		parser.c \
		parse_ambient_light.c\
		custom_exit.c\
		parse_ratio.c\
		parse_vector3.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
