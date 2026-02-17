/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spa_pb_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:41:30 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/17 13:51:37 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	add_to_dest_bonus(t_stack **dest, t_stack *node)
{
	t_stack		*last_node;

	last_node = (*dest)->prev;
	node->next = *dest;
	node->prev = last_node;
	last_node->next = node;
	(*dest)->prev = node;
	*dest = node;
}

static int	push_check(t_stack **dest, t_stack **src)
{
	t_stack		*node;

	if (!src || !*src)
		return (0);
	node = *src;
	if ((*src)->next == *src)
		*src = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		*src = node->next;
	}
	if (!dest || !*dest)
	{
		*dest = node;
		node->next = node;
		node->prev = node;
	}
	else
		add_to_dest_bonus(dest, node);
	return (1);
}

void	pa_check(t_stack **a, t_stack **b, int print)
{
	if (push_check(a, b))
		if (print == 1)
			write (1, "pa\n", 3);
}

void	pb_check(t_stack **b, t_stack **a, int print)
{
	if (push_check(b, a))
		if (print == 1)
			write (1, "pb\n", 3);
}
