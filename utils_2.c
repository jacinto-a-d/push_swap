/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:54:27 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/11 16:54:29 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_target(t_stack *a, t_stack *b)
{
	t_stack		*current_b;
	t_stack		*target_node;
	long		best_index;

	best_index = -2147483649;
	current_b = b;
	while (1)
	{
		if (current_b->index < a->index && current_b->index > best_index)
		{
			best_index = current_b->index;
			target_node = current_b;
		}
		current_b = current_b->next;
		if (current_b == b)
			break ;
	}
	return (best_index);
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack		*target_node;
	t_stack		*tmp_a;
	long		best_index;

	tmp_a = a;
	target_node = NULL;
	while (1)
	{
		best_index = set_target(a, b);
		if (best_index == -2147483649)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
		if (a == tmp_a)
			break ;
	}
}

t_stack	*find_cheapest(t_stack *stack)
{
	t_stack		*cheapest_node;
	t_stack		*tmp;
	long		best_value;

	if (!stack)
		return (NULL);
	tmp = stack;
	best_value = 2147483648;
	cheapest_node = NULL;
	while (1)
	{
		if (stack->push_cost < best_value)
		{
			best_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
		if (tmp == stack)
			break ;
	}
	return (cheapest_node);
}

void move_node(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (cheapest->above_median && cheapest->target_node->above_median)
	{
		while ((*a) != cheapest && (*b) != cheapest->target_node)
			rr(a, b);
	}
	else if (cheapest->above_median && cheapest->target_node->above_median)
	{ 
		while ((*a) != cheapest && (*b) != cheapest->target_node)
			rrr(a, b);
	}
	while ((*a) != cheapest)
	{
		if ((*a)->above_median)
			ra(a);
		else
			rra(a);
	}
	while ((*b) != cheapest->target_node)
	{
		if ((*b)->above_median)
			rb(b);
		else
			rrb(b);
	}
	pb(b, a);
}
