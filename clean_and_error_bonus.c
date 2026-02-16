/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_error_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:03:43 by dipekko           #+#    #+#             */
/*   Updated: 2026/02/16 11:47:59 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HEADEEEERRRR

#include "push_swap.h"

void	error_and_clean_bonus(char **tmp, t_stack **stack, int n)
{
	int		x;

	x = 0;
	while (tmp[x])
	{
		free(tmp[x]);
		x++;
	}
	free(tmp);
	if (n == 1)
	{
		free_stack_bonus(stack);
		write (2, "Error\n", 6);
		exit(1);
	}
}

void	free_stack_bonus(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	current->prev->next = NULL;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
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
