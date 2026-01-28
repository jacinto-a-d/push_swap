/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:29:26 by dipekko           #+#    #+#             */
/*   Updated: 2026/01/28 16:38:18 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"

t_stack	*create_nodo(int value)
{
	t_stack	*nodo;

	nodo = malloc(sizeof(t_stack));
	if (!nodo)
		return(NULL);
	nodo->value = value;
	nodo->index = 0;
	nodo->push_cost = 0;
	nodo->above_median = 0;
	nodo->target_node = 0;
	nodo->next = 0;
	nodo->prev = 0;
	return (nodo);
}