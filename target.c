/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:07:14 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/13 14:46:49 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*target_b(t_stack *move, t_stack *dest)
{
	t_stack		*current;
	t_stack		*target_node;
	long		best_index;

	best_index = -2147483649;
	target_node = NULL;
	current = dest;
	if (!dest)
		return (0);
	while (1)
	{
		if (current->index < move->index && current->index > best_index)
		{
			best_index = current->index;
			target_node = current;
		}
		current = current->next;
		if (current == dest)
			break ;
	}
	return (target_node);
}

static t_stack	*target_a(t_stack *move, t_stack *dest)
{
	t_stack		*current;
	t_stack		*target_node;
	long		best_index;

	best_index = 2147483649;
	target_node = NULL;
	current = dest;
	if (!dest)
		return (0);
	while (1)
	{
		if (current->index > move->index && current->index < best_index)
		{
			best_index = current->index;
			target_node = current;
		}
		current = current->next;
		if (current == dest)
			break ;
	}
	return (target_node);
}

void	set_target_b(t_stack *b, t_stack *a)
{
	t_stack		*tmp_b;
	t_stack		*best;

	if (!a || !b)
		return ;
	tmp_b = b;
	while (1)
	{

		best = target_b(b, a);
		if (!best)
			b->target_node = find_max(a);
		else
			b->target_node = best;
		b = b->next;
		if (b == tmp_b)
			break ;
	}
}

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack		*tmp_a;
	t_stack		*best;

	if (!a || !b)
		return ;
	tmp_a = a;
	while (1)
	{
		best = target_a(a, b);
		if (!best)
			a->target_node = find_min(b);
		else
			a->target_node = best;
		a = a->next;
		if (a == tmp_a)
			break ;
	}
}