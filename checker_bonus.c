/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:43:47 by dipekko           #+#    #+#             */
/*   Updated: 2026/02/16 11:40:01 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HEADEEER

#include "push_swap.h"

void	check_int_bonus(long num)
{
	if (num < -2147483648 || num > 2147483647)
	{
		write (2, "Error\n", 6);
		exit(1);
	}
	return ;
}

void	check_num_bonus(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+'
			&& str[i] != ' ')
		{
			write (2, "Error\n", 6);
			free(str);
			exit (1);
		}
		i++;
	}
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

void	check_number_bonus(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
	{
		write (2, "Error\n", 6);
		exit (1);
	}
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
		{
			write (2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
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
