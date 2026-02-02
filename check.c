/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:23:22 by dipekko           #+#    #+#             */
/*   Updated: 2026/02/02 19:21:31 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"

int	check_int(int num)
{
	if (num < -2147483648 || num > 2147483647)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (1);
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
			ft_printf("Error\n");
			exit (1);
		}
		i++;
	}
}

void	*check_duplicate(t_stack **stack_a, int num)
{
	t_stack		*tmp;

	if (!stack_a)
		return (1);
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->value == num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	atoi_long_check_int(const char *str)
{
	long	result;
	long	sign;
	int		total;

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
	total = cheack_int(result);
	return (total * sign);
}
