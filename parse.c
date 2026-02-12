/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:48:03 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/11 20:31:38 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*push_swap_init(t_stack *stack, char **argv)
{
	char		**tmp;
	int			i;

	i = 1;
	stack = NULL;
	while (argv[i])
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp)
			return (NULL);
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
	{
		write (2, "ERROR\n", 6);
		exit (1);
	}
	while (tmp[x])
	{
		check_number(tmp[x]);
		num = atoi_long(tmp[x]);
		check_int(num);
		if (check_duplicate(stack, num))
			error_and_clean(tmp, stack, 1);
		new_nodo = create_nodo(num);
		add_nodo_end(stack, new_nodo);
		x++;
	}
}
