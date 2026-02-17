/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srra_rrb_rrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:41:55 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/17 13:41:57 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rev_rotate(t_stack **stack)
{
	if (stack && *stack && (*stack)->next != *stack)
	{
		*stack = (*stack)->prev;
		return (1);
	}
	return (0);
}

void	rra(t_stack **a)
{
	if (rev_rotate(a))
		write (1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	if (rev_rotate(b))
		write (1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	int		tmp_a;
	int		tmp_b;

	tmp_a = rev_rotate(a);
	tmp_b = rev_rotate(b);
	if (tmp_a || tmp_b)
		write (1, "rrr\n", 4);
}
