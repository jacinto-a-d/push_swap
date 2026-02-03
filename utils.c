/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:56:09 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/03 02:50:24 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "push_swap.h"

int	list_size_circular(t_stack *stack)
{
	t_stack	*ptr;
	int		i;

	i = 1;
	ptr = stack->next;
	if (!ptr)
		return (0);
	while (ptr != stack->next)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
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
