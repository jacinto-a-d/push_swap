/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:25:07 by jabad-di          #+#    #+#             */
/*   Updated: 2026/01/28 16:54:37 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
    int				value;          // El número a ordenar
    int				index;          // Posición en el ranking (0 a N)
	int				push_cost;      // Coste de moverlo a la otra pila
	int				above_median;   // Para saber si usamos ra o rra
    struct s_stack	*target_node;   // Puntero al nodo donde debe ir
    struct s_stack	*next;          // Siguiente nodo
    struct s_stack	*prev;          // Nodo anterior (lista doble)
}					t_stack;


t_stack	*create_nodo(void *value);

void	*check_duplicate(t_stack *stack);
void	*check_num(char *str);
void	*init_stack(t_stack **stack_a, char **argv);

int		check_int(long num);
int		atoi_long(const char *str);
int		list_size_circular(t_stack *stack);

char	**ft_split(char const *s, char c);

#endif