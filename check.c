/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:23:22 by dipekko           #+#    #+#             */
/*   Updated: 2026/02/03 18:23:27 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int(long num)
{
	if (num < -2147483648 || num > 2147483647)
	{
		write (2, "Error\n", 6);
		exit(1);
	}
	return ;
}

void	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+'
			&& str[i] != ' ')
		{
			write (2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
}

int	check_duplicate(t_stack **stack_a, int num)
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

void	check_number(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
	{
		write (2, "ERROR\n", 6);
		exit (1);
	}
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
		{
			write (2, "ERROR\n", 6);
			exit (1);
		}
		i++;
	}
}
