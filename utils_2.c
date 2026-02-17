/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:42:06 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/17 19:29:05 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (tmp->push_cost < best_value)
		{
			best_value = tmp->push_cost;
			cheapest_node = tmp;
		}
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
	return (cheapest_node);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
	{
		if (cheapest->above_median && cheapest->target_node->above_median)
			rr(a, b);
		else if (!(cheapest->above_median)
			&& !cheapest->target_node->above_median)
			rrr(a, b);
		else
			break ;
	}
}

void	index_list(t_stack **a)
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

int	find_min_index(t_stack *a)
{
	t_stack	*tmp;
	int		min;

	if (!a)
		return (0);
	tmp = a;
	min = tmp->index;
	while (1)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
		if (tmp == a)
			break ;
	}
	return (min);
}
