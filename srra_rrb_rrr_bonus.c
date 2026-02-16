/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srra_rrb_rrr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:53:37 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/16 11:52:38 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rev_rotate_check(t_stack **stack)
{
	if (stack && *stack && (*stack)->next != *stack)
	{
		*stack = (*stack)->prev;
		return (1);
	}
	return (0);
}

void	rra_check(t_stack **a, int print)
{
	if (rev_rotate_check(a))
		if (print == 1)
			write (1, "rra\n", 4);
}

void	rrb_check(t_stack **b, int print)
{
	if (rev_rotate_check(b))
		if (print == 1)
			write (1, "rrb\n", 4);
}

void	rrr_check(t_stack **a, t_stack **b, int print)
{
	int		tmp_a;
	int		tmp_b;

	tmp_a = rev_rotate_check(a);
	tmp_b = rev_rotate_check(b);
	if (tmp_a || tmp_b)
		if (print == 1)
			write (1, "rrr\n", 4);
}
