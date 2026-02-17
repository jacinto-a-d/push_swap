/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:41:24 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/17 19:25:51 by jabad-di         ###   ########.fr       */
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
	t_stack	*tmp;
	int		min_val;
	int		size;

	if (!a || !*a)
		return ;
	min_val = find_min_index(*a);
	current_pos(*a);
	size = list_size_circular(*a);
	tmp = *a;
	while (tmp->index != min_val)
		tmp = tmp->next;
	while ((*a)->index != min_val)
	{
		if (tmp->pos <= size / 2)
			ra(a);
		else
			rra(a);
	}
}

void	sort_three(t_stack **a)
{
	t_stack	*max_node;

	max_node = find_max(*a);
	if (*a == max_node)
		ra(a);
	else if ((*a)->next == max_node)
		rra(a);
	if ((*a)->index > (*a)->next->index)
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
