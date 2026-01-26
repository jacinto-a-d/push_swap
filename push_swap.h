/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:25:07 by jabad-di          #+#    #+#             */
/*   Updated: 2026/01/26 16:08:23 by jabad-di         ###   ########.fr       */
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

t_stack	*ft_push_swap(t_stack **stack_a, t_stack **stack_b);

#endif