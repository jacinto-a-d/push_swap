/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:56:09 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/06 22:38:52 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_validation_create(t_stack **stack, char **tmp)
{
	int		x;
	long	num;
	t_stack	*new_nodo;

	x = 0;
	num = 0;
	if(!tmp || !tmp[0])
	{
		write (2, "ERROR\n", 6);
		exit (1);
	}
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
	int			x;
	int			size;
	int			median;
	
	x = 0;
	median = 0;
	size = 0;
	if (!stack)
		return ;
	size = list_size_circular(stack);
	median = size / 2;
	tmp = stack;
	while (1)
	{
		if (x <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		if (stack == tmp)
			break;
	}	
}

t_stack *find_max(t_stack *stack)
{
	t_stack 	*max_node;
	t_stack		*tmp;
	long		max_index;
	
	if (!stack)
		return (NULL);
	tmp = stack;
	max_index = -2147483649;
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

t_stack *find_min(t_stack *stack)
{
	t_stack 	*min_node;
	t_stack		*tmp;
	long		min_index;
	
	if (!stack)
		return (NULL);
	tmp = stack;
	min_index = 2147483648;
	while (1)
	{
		if (stack->index > min_index)
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