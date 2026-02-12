/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:29:26 by dipekko           #+#    #+#             */
/*   Updated: 2026/02/12 19:24:16 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	nodo->next = nodo;
	nodo->prev = nodo;
	return (nodo);
}

void	add_nodo_end(t_stack **stack, t_stack *new_nodo)
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

int	list_size_circular(t_stack *stack)
{
	t_stack		*ptr;
	int			i;

	if (!stack)
		return (0);
	i = 1;
	ptr = stack->next;
	while (ptr != stack)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

void move_node(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (cheapest->above_median && cheapest->target_node->above_median)
	{
		while ((*a) != cheapest && (*b) != cheapest->target_node)
			rr(a, b);
	}
	else if (!cheapest->above_median && !cheapest->target_node->above_median)
	{ 
		while ((*a) != cheapest && (*b) != cheapest->target_node)
			rrr(a, b);
	}
	while ((*a) != cheapest)
	{
		if (cheapest->above_median)
			ra(a);
		else
			rra(a);
	}
	while ((*b) != cheapest->target_node)
	{
		if (cheapest->target_node->above_median)
			rb(b);
		else
			rrb(b);
	}
	pb(b, a);
}

void inverse_move_node(t_stack **b, t_stack **a)
{
	t_stack		*cheapest;
	
	cheapest = find_cheapest(*b);
	if (!cheapest->target_node || (*b == cheapest && (*b)->next == *b))
    {	
		pa(a, b);
		return ;
	}
	if (cheapest->above_median && cheapest->target_node->above_median)
		while ((*b) != cheapest && (*a) != cheapest->target_node)
			rr(a, b);
	else if (!cheapest->above_median && !cheapest->target_node->above_median)
		while ((*b) != cheapest && (*a) != cheapest->target_node)
			rrr(a, b);
	while ((*b) != cheapest)
	{
		if (cheapest->above_median)
			rb(b);
		else
			rrb(b);
	}
	while ((*a) != cheapest->target_node)
	{
		if (cheapest->target_node->above_median)
			ra(a);
		else
			rra(a);
	}
	pa(a, b);
}
