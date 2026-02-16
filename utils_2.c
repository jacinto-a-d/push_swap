/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:20:51 by dipekko           #+#    #+#             */
/*   Updated: 2026/02/16 09:34:27 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//FALTRA HEAAAADEEEER
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
