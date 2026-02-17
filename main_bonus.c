/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:40:08 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/17 19:59:24 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	apply_rotations_bonus(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strcmp_bonus(op, "ra\n"))
		ra_check(a, 0);
	else if (!ft_strcmp_bonus(op, "rb\n"))
		rb_check(b, 0);
	else if (!ft_strcmp_bonus(op, "rr\n"))
		rr_check(a, b, 0);
	else if (!ft_strcmp_bonus(op, "rra\n"))
		rra_check(a, 0);
	else if (!ft_strcmp_bonus(op, "rrb\n"))
		rrb_check(b, 0);
	else if (!ft_strcmp_bonus(op, "rrr\n"))
		rrr_check(a, b, 0);
	else
	{
		free(op);
		free_stack_bonus(a);
		free_stack_bonus(b);
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	apply_basic_bonus(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strcmp_bonus(op, "sa\n"))
		sa_check(a, 0);
	else if (!ft_strcmp_bonus(op, "sb\n"))
		sb_check(b, 0);
	else if (!ft_strcmp_bonus(op, "ss\n"))
		ss_check(a, b, 0);
	else if (!ft_strcmp_bonus(op, "pa\n"))
		pa_check(a, b, 0);
	else if (!ft_strcmp_bonus(op, "pb\n"))
		pb_check(b, a, 0);
	else
		apply_rotations_bonus(a, b, op);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		*line;

	if (argc < 2)
		return (0);
	b = NULL;
	a = push_swap_init_bonus(argv);
	if (!a)
		return (1);
	line = get_next_line(0);
	while (line)
	{
		apply_basic_bonus(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted_bonus(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack_bonus(&a);
	if (b)
		free_stack_bonus(&b);
	return (0);
}
