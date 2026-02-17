/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:39:27 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/17 19:24:22 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_and_clean(char **tmp, t_stack **stack, int n)
{
	int		x;

	x = 0;
	if (tmp)
	{
		while (tmp[x])
		{
			free(tmp[x]);
			tmp[x] = NULL;
			x++;
		}
	}
	free(tmp);
	if (n == 1)
	{
		if (stack || *stack)
			free_stack (stack);
		write (2, "Error\n", 6);
		exit(1);
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*next_node;
	int		size;

	if (!stack || !*stack)
		return ;
	size = list_size_circular(*stack);
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
