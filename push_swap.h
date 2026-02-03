/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:25:07 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/03 18:51:52 by jabad-di         ###   ########.fr       */
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
	struct s_stack	*target_node;//puntero al nodo donde debe aterizar 
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack	*create_nodo(int value);
void	add_nodo_end(t_stack **stack, t_stack *new_nodo);
t_stack	*init_stack(t_stack **stack_a, char **argv);

void	error_and_clean(char **tmp, t_stack **stack, int n);
void	process_validation_create(t_stack **stack, char **tmp);
void	free_stack(t_stack **stack);
void	check_number(char *str);
void	check_num(char *str);
void	check_int(long num);
void	index_list(t_stack **stack_a);
void	add_nodo_end(t_stack **stack, t_stack *new_nodo);

int		index_nodo(t_stack **stack_a, int ohter_value);
int		check_duplicate(t_stack **stack, int num);
int		atoi_long(const char *str);
int		list_size_circular(t_stack *stack);

char	**ft_split(char const *s, char c);

#endif