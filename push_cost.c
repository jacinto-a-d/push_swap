/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:53:23 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/15 17:39:40 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cost_rr(t_stack *a)
{
	if (a->pos > a->target_node->pos)
		a->push_cost = a->pos;
	else
		a->push_cost = a->target_node->pos;
}

static void	cost_rrr(t_stack *a, int size_a, int size_b)
{
	int		distance_a;
	int		distance_b;

	distance_a = size_a - a->pos;
	distance_b = size_b - a->target_node->pos;
	if (distance_a > distance_b)
		a->push_cost = distance_a;
	else
		a->push_cost = distance_b;
}

static void	cost_mix(t_stack *a, int size_a, int size_b)
{
	int		cost_a;
	int		cost_b;

	if (a->above_median)
		cost_a = a->pos;
	else
		cost_a = size_a - a->pos;
	if (a->target_node->above_median)
		cost_b = a->target_node->pos;
	else
		cost_b = size_b - a->target_node->pos;
	a->push_cost = cost_a + cost_b;
}

void	push_cost(t_stack *a, int size_a, int size_b)
{
	t_stack	*tmp;

	if (!a)
		return ;
	tmp = a;
	while (1)
	{
		if (tmp->above_median && tmp->target_node->above_median)
			cost_rr(tmp);
		else if (!(tmp->above_median) && !(tmp->target_node->above_median))
			cost_rrr(tmp, size_a, size_b);
		else
			cost_mix(tmp, size_a, size_b);
		tmp = tmp->next;
		if (tmp == a)
			break ;
	}
}
