/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:42:11 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/17 19:28:38 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	index_list_bonus(t_stack **a)
{
	t_stack	*current;
	t_stack	*tmp;
	int		x;

	current = *a;
	while (1)
	{
		x = 0;
		tmp = *a;
		while (1)
		{
			if (tmp->value < current->value)
				x++;
			tmp = tmp->next;
			if (tmp == *a)
				break ;
		}
		current->index = x;
		current = current->next;
		if (current == *a)
			break ;
	}
}

t_stack	*create_nodo_bonus(int value)
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

void	add_nodo_end_bonus(t_stack **stack, t_stack *new_nodo)
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

int	list_size_circular_bonus(t_stack *stack)
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
