/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:29:26 by dipekko           #+#    #+#             */
/*   Updated: 2026/02/02 19:20:22 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"

t_stack	*create_nodo(int value)
{
	t_stack	*nodo;

	nodo = malloc(sizeof(t_stack));
	if (!nodo)
		return (NULL);
	nodo->value = value;
	nodo->index = 0;
	nodo->push_cost = 0;
	nodo->above_median = 0;
	nodo->target_node = NULL;
	nodo->next = NULL;
	nodo->prev = NULL;
	return (nodo);
}

t_stack	*add_nodo_end(t_stack **stack, t_stack *new_nodo)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack == NULL)
	{
		new_nodo->next = new_nodo;
		new_nodo->prev = new_nodo;
		*stack = new_nodo;
	}
	else
	{
		first = *stack;
		last = first->prev;
		last->next = new_nodo;
		new_nodo->prev = last;
		new_nodo->next = first;
		first->prev = new_nodo;
	}
}
