/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:40:39 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/17 14:08:19 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_individual_cost(t_stack *node, int size)
{
	if (node->above_median)
		return (node->pos);
	return (size - node->pos);
}

void	push_cost(t_stack *a, int size_a, int size_b)
{
	t_stack	*tmp;
	int		cost_a;
	int		cost_b;

	tmp = a;
	while (1)
	{
		cost_a = get_individual_cost(tmp, size_a);
		cost_b = get_individual_cost(tmp->target_node, size_b);
		if (tmp->above_median == tmp->target_node->above_median)
		{
			if (cost_a > cost_b)
				tmp->push_cost = cost_a;
			else
				tmp->push_cost = cost_b;
		}
		else
			tmp->push_cost = cost_a + cost_b;
		tmp = tmp->next;
		if (tmp == a)
			break ;
	}
}
