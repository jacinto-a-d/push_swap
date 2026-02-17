/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:40:28 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/17 20:02:09 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*push_swap_init_bonus(char **argv)
{
	char		**tmp;
	int			i;
	t_stack		*stack;

	i = 1;
	stack = NULL;
	while (argv[i])
	{
		tmp = ft_split_bonus(argv[i], ' ');
		if (!tmp)
			return (NULL);
		process_validation_create_bonus(&stack, tmp);
		error_and_clean_bonus(tmp, &stack, 0);
		i++;
	}
	if (stack)
		index_list_bonus(&stack);
	return (stack);
}

void	process_validation_create_bonus(t_stack **stack, char **tmp)
{
	int		x;
	long	num;
	t_stack	*new_nodo;

	x = 0;
	num = 0;
	if (!tmp || !tmp[0])
		error_and_clean_bonus(tmp, stack, 1);
	while (tmp[x])
	{
		if (!check_number_bonus(tmp[x]))
			error_and_clean_bonus(tmp, stack, 1);
		num = atoi_long_bonus(tmp[x]);
		if (!check_int_bonus(num))
			error_and_clean_bonus(tmp, stack, 1);
		if (check_duplicate_bonus(stack, num))
			error_and_clean_bonus(tmp, stack, 1);
		new_nodo = create_nodo_bonus(num);
		add_nodo_end_bonus(stack, new_nodo);
		x++;
	}
}

int	ft_strcmp_bonus(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
