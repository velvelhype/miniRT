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

LIBFT_DIR = ./src/libft
LIBFT = $(LIBFT_DIR)/libft.a

LIBPARSER_DIR = ./src/parser
LIBPARSER = $(LIBPARSER_DIR)/libparser.a


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

$(NAME): $(OBJS) $(LIBFT) $(LIBPARSER)
	make -C src/minilibx-linux
	cp src/minilibx-linux/libmlx_Linux.a ./
	$(CC) -o $(NAME)   $(LIBPARSER) $(LIBFT) $(OBJS) libmlx_Linux.a $(CFLAGS)

$(LIBFT): dummy
	make -C $(LIBFT_DIR)

$(LIBPARSER): dummy
	make -C src/parser

dummy:

clean:
	make clean -C src/minilibx-linux || :
	make clean -C $(LIBFT_DIR) || :
	make -C $(LIBPARSER_DIR) ||  :
	rm -f $(OBJS)

fclean: clean
	make fclean -C src/minilibx-linux || :
	make fclean -C $(LIBFT_DIR) || :
	make fclean -C $(LIBPARSER_DIR) || :
	rm -f $(NAME)
	rm libmlx_Linux.a

re: fclean all
