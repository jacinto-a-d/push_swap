/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:25:07 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/11 20:31:07 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;//numero a ordenar
	int				index;//el numero en la posicion de la lista
	int				push_cost;//los movimientos que tiene que realizar
	int				above_median;//buleano si esta 1 mitad arriba 0 mitad abajo
	int				pos;
	struct s_stack	*target_node;//puntero al nodo donde debe aterizar 
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack	*create_nodo(int value);
t_stack	*push_swap_init(t_stack *stack, char **argv);
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
void	push_cost(t_stack *a, t_stack *b);
void	move_node(t_stack **a, t_stack **b, t_stack *cheapest);
void	inverse_move_node(t_stack **b, t_stack **a, t_stack *cheapest);
void	handle_stacks(t_stack **a, t_stack **b);

int		index_nodo(t_stack **stack_a, int ohter_value);
int		check_duplicate(t_stack **stack, int num);
int		atoi_long(const char *str);
int		list_size_circular(t_stack *stack);
int		is_sorted(t_stack *stack);

char	**ft_split(char const *s, char c);

#endif