NAME        = push_swap
BONUS_NAME	= checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I.

OBJ_DIR			= obj
MANDATORY_DIR	= $(OBJ_DIR)/mandatory
BONUS_DIR		= $(OBJ_DIR)/bonus

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

OBJS		= $(addprefix $(MANDATORY_DIR)/, $(MANDATORY_SRCS:.c=.o))
BONUS_OBJS	= $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS:.c=.o))


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)


all: $(NAME) $(BONUS_NAME)


bonus: $(BONUS_NAME)


$(MANDATORY_DIR)/%.o: %.c | $(MANDATORY_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_DIR)/%.o: %.c | $(BONUS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(MANDATORY_DIR):
	mkdir -p $(MANDATORY_DIR)

$(BONUS_DIR):
	mkdir -p $(BONUS_DIR)


clean:
	rm -rf $(OBJ_DIR)


fclean: clean
	rm -f $(NAME) $(BONUS_NAME)


re: fclean all


.PHONY: all clean fclean re bonus