NAME = miniRT

CC = gcc

# CFLAGS = -O3 -Werror -Wall -Wextra -g -fsanitize=address -Iinclude

HEADERS = src \
			src/libft \
			src/parser \
			src/render \
			src/minilibx-linux \
			src/vector \
			src/ternary_operation \
			src/simple_operation \

INCLUDES = $(addprefix -I, $(HEADERS))
LXFLAGS		=	-lXext -lX11 -lm

LIBFT_DIR = ./src/libft
LIBFT = $(LIBFT_DIR)/libft.a

LIBPARSER_DIR = ./src/parser
LIBPARSER = $(LIBPARSER_DIR)/libparser.a


CFLAGS = -O3 $(INCLUDES) $(LXFLAGS) -g -Wall -Wextra -Werror
# CFLAGS = -O3 -Werror -Wall -Wextra -g -fsanitize=address -Iinclude

SRCS = src/main.c \
	src/render/render.c \
	src/render/my_pixel_put.c \
	src/render/detect_colision.c \
	src/render/make_color.c \
	src/render/is_in_shadow.c \
	src/render/colide_ray_and_objs.c \
	src/render/luminance.c \
	src/render/register_hooks.c\
	src/vector/vector.c \
	src/vector/vector_operations.c \
	src/vector/vector_debug.c \
	src/simple_operation/ternary_operation.c \
	src/simple_operation/simple_operation.c \
	# src/parser/dummy_parse.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBPARSER)
	make -C src/minilibx-linux
	cp src/minilibx-linux/libmlx_Linux.a ./
	$(CC) -o $(NAME) $(OBJS) $(LIBPARSER) $(LIBFT)  libmlx_Linux.a $(CFLAGS)

$(LIBFT): dummy
	make -C $(LIBFT_DIR) bonus

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
	rm -f libmlx_Linux.a

re: fclean all

# this rule should not be submitted

GTEST_DIR = ./test
GTEST_RELEASE = googletest-release-1.11.0
GTEST = $(GTEST_DIR)/$(GTEST_RELEASE)


$(GTEST):
	curl -OL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
	tar -xvzf release-1.11.0.tar.gz $(GTEST_RELEASE)
	rm -rf release-1.11.0.tar.gz
	mkdir -p $(GTEST_RELEASE)/lib
	cmake -S $(GTEST_RELEASE) -B $(GTEST_RELEASE)/lib
	make -C $(GTEST_RELEASE)/lib
	mv googletest-release-1.11.0 $(GTEST_DIR)

test: test-build
	./test/tester || :
	@rm -rf ./test/tester


test-build: $(GTEST)  $(LIBFT) $(LIBPARSER)
	make -C ./test re
