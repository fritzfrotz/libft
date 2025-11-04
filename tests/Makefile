NAME = run_tests
CC = cc
CFLAGS = -Wall -Werror -Wextra -I.. -g
RM = rm -f

LIBFT_PATH = ../
LIVFT_A = $(LIBFT_PATH)libft.a


SRCS = main.c \
test_atoi.c \
test_isalnum.c \
test_isalpha.c \
test_isdigit.c \
test_isprint.c \
test_isascii.c \
test_tolower.c \
test_toupper.c \
test_strlen.c \
test_strlcpy.c \
test_strlcat.c \
test_strchr.c \
test_strrchr.c \
test_strnstr.c \
test_strncpm.c



OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

run: $(NAME)
	./$(NAME)

$(LIBFT_A):
	make -C ..

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean run