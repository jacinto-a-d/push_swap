/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:25:07 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/02 19:27:52 by jabad-di         ###   ########.fr       */
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
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack	*create_nodo(void *value);
t_stack	*add_nodo_end(t_stack **stack, t_stack *new_nodo);
t_stack	*init_stack(t_stack **stack_a, char **argv);

void	*check_duplicate(t_stack *stack, int num);
void	error_and_clean(char **tmp, t_stack **stack, int n);
void	free_stack(t_stack **stack);
void	*check_num(char *str);

int		check_int(long num);
int		atoi_long_chack_int(const char *str);
int		list_size_circular(t_stack *stack);

char	**ft_split(char const *s, char c);

#endif