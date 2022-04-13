NAME = tester

CC = gcc


HEADERS = src \
			src/libft \
			src/parser \
			src/render \
			src/minilibx-linux \
			src/vector \
			src/ternary_operation \

INCLUDES = $(addprefix -I../, $(HEADERS))
LXFLAGS		=	-lXext -lX11 -lm

LIBFT_DIR = ../src/libft
LIBFT = $(LIBFT_DIR)/libft.a

LIBPARSER_DIR = ../src/parser
LIBPARSER = $(LIBPARSER_DIR)/libparser.a

CFLAGS = -O3 $(INCLUDES) $(LXFLAGS) -g

RED			=	'\033[31m'
GREEN		=	'\033[32m'
YELLOW		=	'\033[33m'
RESET		=	'\033[0m'


SRCS = src/parser_test.cpp \
		src/test_helper.cpp\
		src/test.cpp\

OBJS = $(SRCS:.cpp=.o)


GTEST_DIR = .
GTEST_RELEASE = googletest-release-1.11.0
GTEST = $(GTEST_DIR)/$(GTEST_RELEASE)

all: $(NAME)

$(NAME): $(OBJS)
	@g++ -std=c++11 $(INCLUDES)  $(OBJS) -L$(LIBFT_DIR) -L$(LIBPARSER_DIR) -lparser -lft  -I./src -I$(GTEST)/googletest/include/ -L$(GTEST)/lib/lib/ -lgtest_main -lgtest -pthread -o $(NAME)


dummy:

%.o: %.cpp
	@echo $(GREEN)"Creating: $@"$(RESET)
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)


re: fclean all
