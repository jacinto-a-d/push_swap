/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_turk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:48:03 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/10 17:52:08 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(t_stack **stack_a, char **argv)
{
	char	**tmp;
	int		i;

	i = 1;
	while (argv[i])
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp)
			return (NULL);
		process_validation_create(stack_a, tmp);
		error_and_clean(tmp, stack_a, 0);
		i++;
	}
	if (*stack_a)
		index_list(stack_a);
	return (*stack_a);
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack		*current_b;
	t_stack		*target_node;
	t_stack		*tmp_a;
	t_stack		*tmp_b;
	long		best_index;

	tmp_a = a;
	tmp_b = b;
	while (1)
	{
		best_index = -2147483649;
		current_b = tmp_b;
		while (1)
		{
			if (current_b->index < a->index && current_b->index > best_index)
			{
				best_index = current_b->index;
				target_node = current_b;
			}
			current_b = current_b->next;
			if (current_b == tmp_b)
				break ;
		}
		if (best_index == -2147483649)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
		if (a == tmp_a)
			break ;
	}	
}

void	push_cost(t_stack *a, t_stack *b)
{
	t_stack		*tmp;
	int			size_a;
	int			size_b;

	if (!a)
		return ;
	size_a = list_size_circular(a);
	size_b = list_size_circular(b);
	tmp = a;
	while (1)
	{
		if (a->above_median)
			a->push_cost = a->pos;
		else
			a->push_cost = size_a - a->pos;
		if (a->target_node->above_median)
			a->push_cost += a->target_node->pos;
		else
			a->push_cost += size_b - a->target_node->pos;
		a = a->next;
		if (a == tmp)
			break ;
	}
}
