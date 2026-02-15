/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:07:14 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/15 21:16:42 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*target_a(t_stack *move, t_stack *a)
{
	t_stack		*current;
	t_stack		*target_node;
	long		best_index;

	best_index = 2147483649;
	target_node = NULL;
	current = a;
	if (!a)
		return NULL;
	while (1)
	{
		if (current->index > move->index && current->index > best_index)
		{
			best_index = current->index;
			target_node = current;
		}
		current = current->next;
		if (current == a)
			break ;
	}
	if (!target_node)
		return (find_max(a));
	return (target_node);
}

static t_stack	*target_b(t_stack *move, t_stack *b)
{
	t_stack		*current;
	t_stack		*target_node;
	long		best_index;

	best_index = 2147483649;
	target_node = NULL;
	current = b;
	if (!b)
		return NULL;
	while (1)
	{
		if (current->index > move->index && current->index < best_index)
		{
			best_index = current->index;
			target_node = current;
		}
		current = current->next;
		if (current == b)
			break ;
	}
	if (!target_node)
		return (find_min(b));
	return (target_node);
}

void	set_target_b(t_stack *b, t_stack *a)
{
	t_stack		*tmp;

	tmp = b;
	while (1)
	{
		tmp->target_node = target_a(tmp, a);
		tmp = tmp->next;
		if (b == tmp)
			break ;
	}
}

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack		*tmp;

	if (!a)
		return ;
	tmp = a;
	while (1)
	{
		tmp->target_node = target_b(tmp, b);
		tmp = tmp->next;
		if (a == tmp)
			break ;
	}
}