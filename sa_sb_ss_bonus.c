/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:53:58 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/16 10:57:39 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//HEADERRRRRR
#include "push_swap.h"

static int	swap_check(t_stack **stack)
{
	int		tmp_val;
	int		tmp_idx;

	if (!stack || !*stack || (*stack)->next == *stack)
		return (0);
	tmp_val = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp_val;
	tmp_idx = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = tmp_idx;
	return (1);
}

void	sa_check(t_stack **a, int print)
{
	if (swap_check(a))
		if (print == 1)
			write (1, "sa\n", 3);
}

void	sb_check(t_stack **b, int print)
{
	if (swap_check(b))
		if (print == 1)
			write (1, "sb\n", 3);
}

void	ss_check(t_stack **a, t_stack **b, int print)
{
	int		tmp_a;
	int		tmp_b;

	tmp_a = swap_check(a);
	tmp_b = swap_check(b);
	if (tmp_a || tmp_b)
		if (print == 1)
			write (1, "ss\n", 3);
}
