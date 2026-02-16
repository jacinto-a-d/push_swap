/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:26:48 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/16 09:29:22 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	sorted_small(t_stack **a, t_stack **b)
{
	int	size;

	size = list_size_circular(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
		handle_stacks(a, b);
}

void	handle_stacks(t_stack **a, t_stack **b)
{
	if ((list_size_circular(*a)) > 3)
		pb(b, a);
	if ((list_size_circular(*a)) > 3)
		pb(b, a);
	while ((list_size_circular(*a)) > 3)
	{
		current_pos(*a);
		current_pos(*b);
		get_above_median(*a);
		get_above_median(*b);
		set_target_a(*a, *b);
		push_cost(*a, list_size_circular(*a), list_size_circular(*b));
		move_node(a, b, find_cheapest(*a));
	}
	sort_three(a);
	while (*b)
	{
		current_pos(*a);
		get_above_median(*a);
		set_target_b(*b, *a);
		inverse_move_node(b, a, *b);
	}
	min_on_top(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	a = push_swap_init(argv);
	if (!a)
		return (0);
	index_list(&a);
	if (is_sorted(a) == 0)
		sorted_small(&a, &b);
	free_stack(&a);
	if (b)
		free_stack(&b);
	return (0);
}
