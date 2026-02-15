/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:56:09 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/15 18:26:35 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	get_above_median(t_stack *stack)
{
	t_stack		*tmp;
	int			i;
	int			median;

	if (!stack)
		return ;
	i = 0;
	median = list_size_circular(stack) / 2;
	tmp = stack;
	while (1)
	{
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
		if (stack == tmp)
			break ;
	}
}

t_stack	*find_max(t_stack *stack)
{
	t_stack		*max_node;
	t_stack		*tmp;
	long		max_index;

	if (!stack)
		return (NULL);
	tmp = stack;
	max_index = -2147483649;
	max_node = NULL;
	while (1)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			max_node = stack;
		}
		stack = stack->next;
		if (stack == tmp)
			break ;
	}
	return (max_node);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack			*tmp;
	t_stack			*min_node;
	long			min_index;

	min_index = 2147483649;
	if (!stack)
		return (NULL);
	tmp = stack;
	min_node = NULL;
	while (1)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			min_node = stack;
		}
		stack = stack->next;
		if (stack == tmp)
			break ;
	}
	return (min_node);
}

void    current_pos(t_stack *stack)
{
    int     i;
    t_stack *tmp;

    if (!stack)
        return ;
    i = 0;
    tmp = stack;
    while (1)
    {
        stack->pos = i;
		i++;
        stack = stack->next;
        if (stack == tmp)
            break ;
    }
}