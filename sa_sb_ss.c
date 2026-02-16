/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:53:58 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/16 09:25:34 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack **stack)
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

void	sa(t_stack **a)
{
	if (swap(a))
		write (1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	if (swap(b))
		write (1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	int		tmp_a;
	int		tmp_b;

	tmp_a = swap(a);
	tmp_b = swap(b);
	if (tmp_a || tmp_b)
		write (1, "ss\n", 3);
}
