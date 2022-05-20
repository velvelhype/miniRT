NAME = libparser.a

CC = gcc

HEADERS = ../ \
			../libft \
			../vector \
			../ternary_operation \
			../simple_operation \

INCLUDES = $(addprefix -I, $(HEADERS))
LXFLAGS		=	-lXext -lX11 -lm


CFLAGS = -O3 $(INCLUDES) $(LXFLAGS) -g -Wall -Wextra -Werror
# CFLAGS = -O3 -Werror -Wall -Wextra -g -fsanitize=address -Iinclude

SRCS = get_next_line.c \
		parser.c \
		parse_ambient_light.c\
		custom_exit.c\
		parse_ratio.c\
		parse_vector3.c\
		parse_camera.c\
		parse_light.c\
		parse_objs.c\
		sphere.c\
		plane.c\
		cylinder.c\
		file_open.c\
		parse_color.c\
		# dummy_parse.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
