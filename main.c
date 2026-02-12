/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:26:48 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/11 20:32:02 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = list_size_circular(*a);
	if (len_a-- > 3)
		pb(b, a);
	if (len_a-- > 3)
		pb(b, a);
	while (len_a-- > 3)
	{
		index_list(a);
		index_list(b);
		get_above_median(*a);
		get_above_median(*b);
		set_target_b(*a, *b);
		push_cost(*a, *b);
		move_node(a, b, find_cheapest(*a));
	}
	sort_three(a);
	inverse_move_node(b, a, find_cheapest(*b));
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
	push_swap_init(a, argv);
	if (!a)
		return (0);
	is_sorted(a);
	if (list_size_circular(a) == 2)
	{
		sa(&a);
	}
	else if (list_size_circular(a) == 3)
		sort_three(&a);
	else if (list_size_circular(a) > 3)
		handle_stacks(&a, &b);
	free_stack(&a);
	if (b)
		free_stack(&b);
	return (0);
}