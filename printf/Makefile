NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = 			ft_put_char_ascii.c\
				ft_put_char_ptr.c\
				ft_put_int.c\
				ft_put_unsigned_int.c\
				ft_put_hex_may.c\
				ft_put_hex_min.c\
				ft_printf.c\
				ft_put_void.c\
				ft_atoi.c\
				ft_itoa.c\
				ft_itoa_unsigned.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
