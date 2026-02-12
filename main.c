/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:26:48 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/12 19:54:32 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void handle_stacks(t_stack **a, t_stack **b)
{
	t_stack *node_a;
	
	if ((list_size_circular(*a)) > 3)
		pb(b, a);
	if ((list_size_circular(*a)) > 3)
		pb(b, a);
	while ((list_size_circular(*a)) > 3 && !is_sorted(*a))
    {
        current_pos(*a);
        current_pos(*b);
        get_above_median(*a);
        get_above_median(*b);
        set_target_b(*a, *b);
        push_cost(*a, *b);
        node_a = find_cheapest(*a);
        if (!node_a)
            break;
        move_node(a, b, node_a);
    }
    sort_three(a);
    while (list_size_circular(*b) > 0)
    {
        current_pos(*a);
        current_pos(*b);
        get_above_median(*a);
        get_above_median(*b);
        set_target_a(*b, *a);
        push_cost(*a, *b);
        inverse_move_node(b, a);
    }
    current_pos(*a);
	get_above_median(*a);
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
			sa(&a);
		}
		else if (list_size_circular(a) == 3)
			sort_three(&a);
		else if (list_size_circular(a) > 3)
			handle_stacks(&a, &b);
		if (b)
		free_stack(&b);
	}
	free_stack(&a);
	return (0);
}