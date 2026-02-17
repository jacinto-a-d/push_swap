NAME        = push_swap
BONUS_NAME = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

MANDATORY_SRCS = parse.c \
              clean_and_error.c \
			  push_cost.c \
              ft_split.c \
              nodos.c \
			  target.c \
              check.c \
              utils.c \
			  utils_2.c \
			  sort_small.c \
			  sa_sb_ss.c \
			  spa_pb.c \
			  sra_rb_rr.c \
			  srra_rrb_rrr.c \
			  main.c \

BONUS_SRCS = utils_bonus.c \
			srra_rrb_rrr_bonus.c \
			sra_rb_rr_bonus.c \
			spa_pb_bonus.c \
			sa_sb_ss_bonus.c \
			ft_split_bonus.c \
			parse_bonus.c \
			main_bonus.c \
			get_next_line.c \
			get_next_line_utils.c \
			clean_and_error_bonus.c \
			checker_bonus.c \

OBJS        = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus