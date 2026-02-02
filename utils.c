/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:56:09 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/02 19:30:09 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "push_swap.h"

int	list_size_circular(t_stack *stack)
{
	t_stack	*ptr;
	int		i;

	i = 1;
	ptr = stack->next;
	if (!ptr)
		return (0);
	while (ptr != stack->next)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}
