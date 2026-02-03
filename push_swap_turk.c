/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_turk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:48:03 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/03 19:17:20 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(t_stack **stack_a, char **argv)
{
	char	**tmp;
	long	num;
	int		i;
	int		x;

	i = 1;
	num = 0;
	while (argv[i])
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp)
			return (NULL);
		x = 0;
		process_validation_create(stack_a, tmp);
		error_and_clean(tmp, stack_a, 0);
		i++;
	}
	if (*stack_a)
		index_list(stack_a);
	return (*stack_a);
}
