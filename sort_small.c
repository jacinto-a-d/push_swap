/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:54:27 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/15 21:21:26 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*head;

	if (!stack)
		return (0);
	head = stack;
	while (stack->next != head)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	min_on_top(t_stack **a)
{
	t_stack	*min;

	min = find_max(*a);
	current_pos(*a);
	get_above_median(*a);
	while (*a != min)
	{
		if (min->above_median)
			ra(a);
		else
			rra(a);
	}
}


void	sort_three(t_stack **a)
{
	t_stack	*max;

	max = find_max(*a);
	if (*a == max)
		ra(a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	min_on_top(a);
	pb(b, a);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	min_on_top(a);
	pb(b, a);
	min_on_top(a);
	pb(b, a);
	sort_three(a);
	pa(a, b);
	pa(a, b);
	min_on_top(a);
}