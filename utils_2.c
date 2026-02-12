/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:54:27 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/12 19:44:48 by jabad-di         ###   ########.fr       */
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

void	min_on_top(t_stack **a)
{
	t_stack	*min;

	min = find_min(*a);
	while (*a != min)
	{
		if (min->above_median)
			ra(a);
		else
			rra(a);
	}
}

void    current_pos(t_stack *stack)
{
    int     i;
    t_stack *tmp;

    if (!stack)
        return ;
    i = 0;
    tmp = stack;
    while (1)
    {
        stack->pos = i;
		i++;
        stack = stack->next;
        if (stack == tmp)
            break ;
    }
}
