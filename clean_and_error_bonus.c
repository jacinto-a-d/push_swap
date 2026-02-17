/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_error_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:38:59 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/17 20:22:45 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_and_clean_bonus(char **tmp, t_stack **stack, int n)
{
	int		x;

	x = 0;
	if (tmp)
	{
		while (tmp[x])
		{
			free(tmp[x]);
			x++;
		}
		free(tmp);
	}
	if (n == 1)
	{
		if (stack && *stack)
			free_stack_bonus(stack);
		write (2, "Error\n", 6);
		exit(1);
	}
}

void	free_stack_bonus(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*next_node;
	int		size;

	if (!stack || !*stack)
		return ;
	size = list_size_circular_bonus(*stack);
	tmp = *stack;
	while (size > 0)
	{
		next_node = tmp->next;
		free(tmp);
		tmp = next_node;
		size--;
	}
	*stack = NULL;
}

int	atoi_long_bonus(const char *str)
{
	long	result;
	long	sign;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
