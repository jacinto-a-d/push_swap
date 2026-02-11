/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:53:23 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/11 15:29:40 by jabad-di         ###   ########.fr       */
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

	if (!a)
		return ;
	size_a = list_size_circular(a);
	size_b = list_size_circular(b);
	tmp = a;
	while (1)
	{
		if (a->above_median && a->target_node->above_median)
			cost_rr(a);
		else if (!(a->above_median) && !(a->target_node->above_median))
			cost_rrr(a, size_a, size_b);
		else
			cost_mix(a, size_a, size_b);
		a = a->next;
		if (tmp == a)
			break ;
	}
}
