/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:38:51 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/17 17:38:40 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_int_bonus(long num)
{
	if (num < -2147483648 || num > 2147483647)
		return (0);
	return (1);
}

int	check_duplicate_bonus(t_stack **stack_a, int num)
{
	t_stack		*tmp;
	t_stack		*init;

	if (!stack_a || !*stack_a)
		return (0);
	init = *stack_a;
	tmp = init;
	while (1)
	{
		if (tmp->value == num)
			return (1);
		tmp = tmp->next;
		if (tmp == init)
			break ;
	}
	return (0);
}

int	check_number_bonus(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted_bonus(t_stack *stack)
{
	t_stack	*head;

	if (!stack)
		return (0);
	head = stack;
	while (stack->next != head)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
