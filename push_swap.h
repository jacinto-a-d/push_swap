/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:25:07 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/16 11:58:49 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	int				above_median;
	int				pos;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack	*create_nodo(int value);
t_stack	*push_swap_init(char **argv);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_cheapest(t_stack *stack);

void	add_nodo_end(t_stack **stack, t_stack *new_nodo);
void	error_and_clean(char **tmp, t_stack **stack, int n);
void	process_validation_create(t_stack **stack, char **tmp);
void	free_stack(t_stack **stack);
void	check_number(char *str);
void	check_num(char *str);
void	check_int(long num);
void	index_list(t_stack **stack_a);
void	add_nodo_end(t_stack **stack, t_stack *new_nodo);
void	get_above_median(t_stack *stack);
void	rrr(t_stack **a, t_stack **b);
void	rrb(t_stack **b);
void	rra(t_stack **a);
void	rr(t_stack **a, t_stack **b);
void	rb(t_stack **b);
void	ra(t_stack **a);
void	pb(t_stack **b, t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	sb(t_stack **b);
void	sa(t_stack **a);
void	sort_three(t_stack **a);
void	min_on_top(t_stack **a);
void	set_target_b(t_stack *a, t_stack *b);
void	set_target_a(t_stack *a, t_stack *b);
void	push_cost(t_stack *a, int size_a, int size_b);
void	move_node(t_stack **a, t_stack **b, t_stack *cheapest);
void	inverse_move_node(t_stack **b, t_stack **a, t_stack *node);
void	handle_stacks(t_stack **a, t_stack **b);
void	current_pos(t_stack *stack);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);

int		index_nodo(t_stack *stack_a, int ohter_value);
int		check_duplicate(t_stack **stack, int num);
int		atoi_long(const char *str);
int		list_size_circular(t_stack *stack);
int		is_sorted(t_stack *stack);

char	**ft_split(char const *s, char c);

//bonus

t_stack	*push_swap_init_bonus(char **argv);
t_stack	*create_nodo_bonus(int value);

void	process_validation_create_bonus(t_stack **stack, char **tmp);
void	free_stack_bonus(t_stack **stack);
void	check_int_bonus(long num);
void	check_num_bonus(char *str);
void	check_number_bonus(char *str);
void	rra_check(t_stack **a, int print);
void	rrb_check(t_stack **b, int print);
void	rrr_check(t_stack **a, t_stack **b, int print);
void	ra_check(t_stack **a, int print);
void	rb_check(t_stack **b, int print);
void	rr_check(t_stack **a, t_stack **b, int print);
void	pa_check(t_stack **a, t_stack **b, int print);
void	pb_check(t_stack **b, t_stack **a, int print);
void	sa_check(t_stack **a, int print);
void	sb_check(t_stack **b, int print);
void	ss_check(t_stack **a, t_stack **b, int print);
void	apply_basic_bonus(t_stack **a, t_stack **b, char *op);
void	error_and_clean_bonus(char **tmp, t_stack **stack, int n);
void	add_nodo_end_bonus(t_stack **stack, t_stack *new_nodo);
void	index_list_bonus(t_stack **a);

char	*get_next_line(int fd);
char	*ft_extract_line(char *stash);
char	*ft_stash_clean(char *stash);
char	*ft_strchr(const char *str, int c);
char	*ft_strcat(char *dest, const char *src);
char	*ft_read_and_strchr(int fd, char *stash);
char	*ft_str_malloc_concat(char *s1, char *s2);
char	*ft_init_buffer(char *stash);
char	*ft_clean_exit(char *stash, char *tmp);
char	**ft_split_bonus(char const *s, char c);

size_t	ft_strlcat(char *dest, const char *src, size_t destsize);
size_t	ft_strlen(const char *str);

int		ft_strcmp_bonus(char *s1, char *s2);
int		atoi_long_bonus(const char *str);
int		is_sorted_bonus(t_stack *stack);
int		index_nodo_bonus(t_stack *stack_a, int other_value);
int		check_duplicate_bonus(t_stack **stack_a, int num);

#endif