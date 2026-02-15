/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:26:48 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/15 21:24:41 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void handle_stacks(t_stack **a, t_stack **b)
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
        current_pos(*b);
        get_above_median(*a);
        get_above_median(*b);
        set_target_b(*b, *a);
        inverse_move_node(b, a, find_cheapest(*b));
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
	if (is_sorted(a) == 0)
	{
		if (list_size_circular(a) == 2)
		{
			if (a->value > a->next->value)
				sa(&a);
			else
				return (1);
		}
		else if (list_size_circular(a) == 3)
			sort_three(&a);
		else if (list_size_circular(a) == 4)
			sort_four(&a, &b);
		else if (list_size_circular(a) == 5)
			sort_five(&a, &b);
		else if (list_size_circular(a) > 5)
			handle_stacks(&a, &b);
		if (b)
		free_stack(&b);
	}
	free_stack(&a);
	return (0);
}
