/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:41:05 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/17 18:53:44 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

int		check_duplicate(t_stack **stack, int num);
int		atoi_long(const char *str);
int		list_size_circular(t_stack *stack);
int		is_sorted(t_stack *stack);
int		check_number(char *str);
int		check_int(long num);
int		find_min_index(t_stack *a);

char	**ft_split(char const *s, char c);

#endif