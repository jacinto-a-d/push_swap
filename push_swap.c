/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:48:03 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/02 19:22:23 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "push_swap.h"

t_stack	*init_stack(t_stack **stack_a, char **argv)
{
	char	**tmp;
	int		num;
	int		i;
	int		x;
	t_stack	*new_nodo;

	i = 0;
	num = 0;
	while (argv[i])
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp)
			return (NULL);
		x = 0;
		while (tmp[x])
		{
			num = atoi_long_check_int(tmp[x]);
			if (check_duplicate(*stack_a, num))
				error_and_clean(tmp, stack_a, 1);
			new_nodo = create_node(num);
			add_nodo_end(stack_a, new_nodo);
			x++;
		}
		error_and_clean(tmp, stack_a, 0);
		i++;
	}
	return (*stack_a);
}
