NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f


SRCS = ft_atoi.c\
ft_isalnum.c \
ft_isalpha.c \
ft_isdigit.c \
ft_isprint.c \
ft_isascii.c \
ft_tolower.c \
ft_toupper.c \
ft_strlen.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_strchr.c \
ft_strrchr.c \
ft_strnstr.c \
ft_strncmp.c \
ft_memcpy .c \
ft_memset.c \
ft_bzero.c \
ft_memchr.c \
ft_memcmp.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c 








OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

