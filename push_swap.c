/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:48:03 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/03 02:50:38 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*init_stack(t_stack **stack_a, char **argv)
{
	char	**tmp;
	long	num;
	int		i;
	int		x;
	t_stack	*new_nodo;

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
	return (*stack_a);
}
