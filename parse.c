/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:40:33 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/18 20:20:08 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*push_swap_init(char **argv)
{
	char		**tmp;
	int			i;
	t_stack		*stack;

	i = 1;
	stack = NULL;
	while (argv[i])
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp)
			return (NULL);
		if (!tmp[0])
			error_and_clean(tmp, &stack, 1);
		process_validation_create(&stack, tmp);
		error_and_clean(tmp, &stack, 0);
		i++;
	}
	if (stack)
		index_list(&stack);
	return (stack);
}

void	process_validation_create(t_stack **stack, char **tmp)
{
	int		x;
	long	num;
	t_stack	*new_nodo;

	x = 0;
	num = 0;
	if (!tmp || !tmp[0])
		error_and_clean(tmp, stack, 1);
	while (tmp[x])
	{
		if (!check_number(tmp[x]))
			error_and_clean(tmp, stack, 1);
		num = atoi_long(tmp[x]);
		if (!check_int(num))
			error_and_clean(tmp, stack, 1);
		if (check_duplicate(stack, num))
			error_and_clean(tmp, stack, 1);
		new_nodo = create_nodo(num);
		add_nodo_end(stack, new_nodo);
		x++;
	}
}
