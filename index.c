/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:35:52 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/16 09:31:59 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	index_nodo(t_stack *stack_a, int other_value)
{
	t_stack		*tmp;
	int			count;

	if (!stack_a)
		return (0);
	count = 0;
	tmp = stack_a;
	while (1)
	{
		if (tmp->value < other_value)
			count++;
		tmp = tmp->next;
		if (tmp == stack_a)
			break ;
	}
	return (count);
}

void	index_list(t_stack **a)
{
	t_stack	*current;
	t_stack	*tmp;
	int		x;

	current = *a;
	while (1)
	{
		x = 0;
		tmp = *a;
		while (1)
		{
			if (tmp->value < current->value)
				x++;
			tmp = tmp->next;
			if (tmp == *a)
				break ;
		}
		current->index = x;
		current = current->next;
		if (current == *a)
			break ;
	}
}
