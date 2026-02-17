/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:42:16 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/17 13:42:18 by jabad-di         ###   ########.fr       */
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
			tmp->above_median = 1;
		else
			tmp->above_median = 0;
		tmp = tmp->next;
		i++;
		if (stack == tmp)
			break ;
	}
}

t_stack	*find_max(t_stack *stack)
{
	t_stack		*max_node;
	t_stack		*tmp;

	if (!stack)
		return (NULL);
	tmp = stack->next;
	max_node = stack;
	while (tmp != stack)
	{
		if (tmp->index > max_node->index)
			max_node = tmp;
		tmp = tmp->next;
	}
	return (max_node);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack			*tmp;
	t_stack			*min_node;

	if (!stack)
		return (NULL);
	tmp = stack->next;
	min_node = stack;
	while (tmp != stack)
	{
		if (tmp->index < min_node->index)
			min_node = tmp;
		tmp = tmp->next;
	}
	return (min_node);
}

void	current_pos(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

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
