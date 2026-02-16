/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sra_rb_rr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:54:13 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/16 11:04:36 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_check(t_stack **stack)
{
	if (stack && *stack && (*stack)->next != *stack)
	{
		*stack = (*stack)->next;
		return (1);
	}
	return (0);
}

void	ra_check(t_stack **a, int print)
{
	if (rotate_check(a))
		if (print == 1)
			write (1, "ra\n", 3);
}

void	rb_check(t_stack **b, int print)
{
	if (rotate_check(b))
		if (print == 1)
			write (1, "rb\n", 3);
}

void	rr_check(t_stack **a, t_stack **b, int print)
{
	int		tmp_a;
	int		tmp_b;

	tmp_a = rotate_check(a);
	tmp_b = rotate_check(b);
	if (tmp_a || tmp_b)
		if (print == 1)
			write (1, "rr\n", 3);
}
