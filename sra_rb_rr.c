/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sra_rb_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:54:13 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/11 15:18:43 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack **stack)
{
	if (stack && *stack && (*stack)->next != *stack)
	{
		*stack = (*stack)->next;
		return (1);
	}
	return (0);
}

void	ra(t_stack **a)
{
	if (rotate(a))
		write (1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	if (rotate(b))
		write (1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	int		tmp_a;
	int		tmp_b;

	tmp_a = rotate(a);
	tmp_b = rotate(b);
	if (tmp_a || tmp_b)
		write (1, "rr\n", 3);
}
