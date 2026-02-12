/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:35:52 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/12 18:32:06 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	index_nodo(t_stack **stack_a, int other_value)
{
	t_stack		*tmp;
	int			count;

	if (!stack_a ||!*stack_a)
		return (0);
	count = 0;
	tmp = *stack_a;
	while (1)
	{
		if (other_value < tmp->value)
			count++;
		tmp = tmp->next;
		if (tmp == *stack_a)
			break ;
	}
	return (count);
}


void	index_list(t_stack **stack_a)
{
	t_stack	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = *stack_a;
	while (1)
	{
		tmp->index = index_nodo(stack_a, tmp->value);
		tmp = tmp->next;
		if (tmp == *stack_a)
			break ;
	}
}
