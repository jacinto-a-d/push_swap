NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRCS        = push_swap_turk.c \
              clean_and_error.c \
              split.c \
              nodos.c \
              check.c \
              index.c \
              utils.c \
			  main.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re