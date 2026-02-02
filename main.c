/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:02:17 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/02 19:02:41 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "printf/ft_printf.h"
#include "push_swap.h" // Asegúrate de tener tus prototipos aquí

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*aux;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	
	// Llamamos a tu función pasándole el puntero a la dirección de stack_a
	init_stack(&stack_a, argv);

	// --- BLOQUE DE COMPROBACIÓN ---
	if (!stack_a)
	{
		printf("El stack está vacío o hubo un error.\n");
		return (1);
	}

	printf("Contenido del Stack A (Circular):\n");
	aux = stack_a;
	// Al ser circular, usamos un do-while para imprimir hasta volver al inicio
	do
	{
		printf("Nodo: %d\n", aux->value);
		aux = aux->next;
	} while (aux != stack_a);

	// Comprobamos la circularidad hacia atrás (prev)
	printf("Último nodo conectado al primero (prev): %d\n", stack_a->prev->value);

	// --- LIMPIEZA FINAL ---
	// Usamos tu función free_stack para no dejar leaks al terminar el programa
	free_stack(&stack_a);
	
	if (stack_a == NULL)
		printf("Memoria liberada correctamente.\n");

	return (0);
}