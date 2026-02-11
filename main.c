/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:26:48 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/11 17:07:58 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función pequeña para ordenar exactamente 3 números en A
static void	sort_three(t_stack **a)
{
	t_stack	*max;

	max = find_max(*a);
	if (*a == max)
		ra(a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

// Función final para que el número más pequeño quede arriba de todo
static void	min_on_top(t_stack **a)
{
	t_stack	*min;

	min = find_min(*a);
	while (*a != min)
	{
		if (min->above_median)
			ra(a);
		else
			rra(a);
	}
}

// El motor que coordina el algoritmo "Turk"
void	handle_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = list_size_circular(*a);
	// 1. Mandamos nodos a B hasta que solo queden 3 en A
	// Mandamos los dos primeros de golpe para empezar
	if (len_a-- > 3)
		pb(b, a);
	if (len_a-- > 3)
		pb(b, a);
	while (len_a-- > 3)
	{
		index_list(a); // Actualiza posiciones
		index_list(b);
		get_above_median(*a); // Calcula medianas
		get_above_median(*b);
		set_target_b(*a, *b); // Busca objetivos
		push_cost(*a, *b);    // Calcula precios
		// Aquí deberías llamar a move_node con el cheapest
		// move_node(a, b, find_cheapest(*a));
	}
	sort_three(a);
	// 2. Aquí vendría la lógica para devolver de B a A
	// (Normalmente otra función similar a move_node pero inversa)
	min_on_top(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	// Inicializamos y validamos (parseo)
	push_swap_init(&a, argv);
	if (!a)
		return (0);
	// Si no está ordenado, entramos en acción
	// Nota: Falta definir is_sorted o similar
	if (list_size_circular(a) == 2)
		sa(&a);
	else if (list_size_circular(a) == 3)
		sort_three(&a);
	else if (list_size_circular(a) > 3)
		handle_stacks(&a, &b);
	free_stack(&a);
	// Si b no está vacía por algún error, liberarla también
	if (b)
		free_stack(&b);
	return (0);
}