NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c \
	srcs/ft_putnbr.c \
	srcs/ft_putstr.c \
	srcs/ft_strlen.c \
	srcs/ft_puthex.c \
	srcs/ft_putchar.c \
	srcs/ft_convert_and_put.c \
	srcs/ft_putu.c \
	srcs/ft_putptr.c \
	srcs/ft_strdup.c \
	srcs/utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re