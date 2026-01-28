/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:23:22 by dipekko           #+#    #+#             */
/*   Updated: 2026/01/28 16:54:31 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cabiar HEADERR !!!!!!

#include "push_swap.h"
#include "printf/ft_printf.h"

int	check_int(int num)
{
	if (num < -2147483648 || num > 2147483647)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return(1);
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

void	*check_duplicate(t_stack *stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = stack;
	while (current != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->value == checker->value)
			{
				ft_printf("Error\n");
				exit (1);
			}
			checker = checker->next;
		}
		current = current->next;
	}
}

int	atoi_long(const char *str)
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



