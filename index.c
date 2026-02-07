/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:35:52 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/06 22:29:00 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_nodo(t_stack **stack_a, int other_value)
{
	t_stack		*tmp;
	int			count;

	count = 0;
	if ((*stack_a)->value < other_value)
		count++;
	tmp = (*stack_a)->next;
	while (tmp != (*stack_a))
	{
		if (tmp->value < other_value)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

void	index_list(t_stack **stack_a)
{
	t_stack	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	(*stack_a)->index = index_nodo(stack_a, (*stack_a)->value);
	tmp = (*stack_a)->next;
	while (tmp != (*stack_a))
	{
		tmp->index = index_nodo(stack_a, tmp->value);
		tmp = tmp->next;
	}
}
