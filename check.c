/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:23:22 by dipekko           #+#    #+#             */
/*   Updated: 2026/02/03 02:51:33 by dipekko          ###   ########.fr       */
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

void	*check_num(char *str)
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

void	process_validation_create(t_stack **stack, char **tmp)
{
	int		x;
	long	num;
	t_stack	*new_nodo;

	x = 0;
	num = 0;
	while (tmp[x])
	{
		check_number(tmp[x]);
		num = atoi_long(tmp[x]);
		check_int(num);
		if (check_duplicate(stack, num))
			error_and_clean(tmp, stack, 1);
		new_nodo = create_nodo(num);
		add_nodo_end(stack, new_nodo);
		x++;
	}
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
