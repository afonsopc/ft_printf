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
	srcs/utils.c \
	srcs/ft_strlcat.c \
	srcs/ft_strlcpy.c \
	srcs/ft_strjoin.c \
	srcs/ft_memset.c \
	flag_parsing.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

bonus: all

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)..."
	@ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@echo "Cleaning $(NAME)..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re