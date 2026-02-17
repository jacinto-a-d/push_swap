/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:41:12 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/17 13:51:32 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
