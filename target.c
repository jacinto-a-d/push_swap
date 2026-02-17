/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:42:00 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/17 13:42:01 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*target_b(t_stack *move, t_stack *b)
{
	t_stack		*current;
	t_stack		*target_node;
	long		best_index;

	best_index = -2147483649;
	target_node = NULL;
	current = b;
	if (!b)
		return (0);
	while (1)
	{
		if (current->index < move->index && current->index > best_index)
		{
			best_index = current->index;
			target_node = current;
		}
		current = current->next;
		if (current == b)
			break ;
	}
	if (!target_node)
		return (find_max(b));
	return (target_node);
}

static t_stack	*target_a(t_stack *move, t_stack *a)
{
	t_stack		*current;
	t_stack		*target_node;
	long		best_index;

	best_index = 2147483649;
	target_node = NULL;
	current = a;
	if (!a)
		return (0);
	while (1)
	{
		if (current->index > move->index && current->index < best_index)
		{
			best_index = current->index;
			target_node = current;
		}
		current = current->next;
		if (current == a)
			break ;
	}
	if (!target_node)
		return (find_min(a));
	return (target_node);
}

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack		*tmp;

	if (!a || !b)
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

void	set_target_b(t_stack *b, t_stack *a)
{
	t_stack		*tmp;

	if (!a || !b)
		return ;
	tmp = b;
	while (1)
	{
		tmp->target_node = target_a(tmp, a);
		tmp = tmp->next;
		if (b == tmp)
			break ;
	}
}
