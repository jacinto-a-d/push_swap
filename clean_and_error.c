/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:48:18 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/03 13:12:19 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_and_clean(char **tmp, t_stack **stack, int n)
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
		free_stack (stack);
		write (2, "ERROR\n", 6);
		exit(1);
	}
}

void	free_stack(t_stack **stack)
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
