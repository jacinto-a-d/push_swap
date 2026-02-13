/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:53:23 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/14 00:17:50 by dipekko          ###   ########.fr       */
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

void	push_cost(t_stack *a, t_stack *b)
{
	t_stack		*tmp;
	int			size_a;
	int			size_b;
	int			dist_a;
	int			dist_b;
	int			cost_a;
	int			cost_b;

	cost_a = 0;
	const_b = 0;
	dist_a = 0;
	dist_b = 0;
	size_a = list_size_circular(a);
	size_b = list_size_circular(b);
	if (!a)
		return ;
	tmp = a;
	while (1)
	{
		if (tmp->above_median && tmp->target_node->above_median)
		{
			if (tmp->pos > tmp->target_node->pos)
				tmp->push_cost = tmp->pos;
			else
				tmp->push_cost = tmp->target_node->pos;
		}
		else if (!(tmp->above_median) && !(tmp->target_node->above_median))
		{
			dist_a = size_a - tmp->pos;
			dist_b = size_b - tmp->target_node->pos; 
			if (dist_a > dist_b)
				tmp->push_cost = dist_a;
			else
				tmp->push_cost = dist_b;
		}
		else
		{
			cost_a = tmp->above_median
		}
		a = a->next;
		if (tmp == a)
			break ;
	}
}
