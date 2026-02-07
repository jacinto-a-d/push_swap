/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipekko <dipekko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:26:48 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/06 21:00:39 by dipekko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // Para printf

// Función para imprimir lista circular

#include "push_swap.h"

// Crea un nodo nuevo
t_stack	*stack_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = node; // En circular, un solo nodo apunta a sí mismo
	return (node);
}

// Añade un nodo al final y mantiene el círculo
void	stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = *stack;
	// Buscamos el último: en circular, el último es el que apunta al primero
	while (last->next != *stack)
		last = last->next;
	
	last->next = new_node;   // El viejo último apunta al nuevo
	new_node->next = *stack; // El nuevo apunta al primero (cerramos el círculo)
}

void print_circular_stack(t_stack *stack, char *name)
{
    if (!stack)
    {
        printf("Stack %s: VACÍO\n", name);
        return;
    }
    t_stack *temp = stack;
    printf("Stack %s: ", name);
    while (1)
    {
        printf("%d ", temp->value);
        temp = temp->next;
        if (temp == stack) // Si volvemos al inicio, paramos
            break;
    }
    printf("(circular OK)\n");
}

int main(void)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    // 1. CREACIÓN DE LA LISTA
    // Importante: Tus funciones de nodos deben cerrar el círculo
    stack_add_back(&a, stack_new(10));
    stack_add_back(&a, stack_new(20));
    stack_add_back(&a, stack_new(30));
    
    // Ponemos algo en B para probar rr
    stack_add_back(&b, stack_new(100));
    stack_add_back(&b, stack_new(200));

    printf("--- ESTADO INICIAL ---\n");
    print_circular_stack(a, "A");
    print_circular_stack(b, "B");
    printf("----------------------\n\n");

    // 2. PRUEBA DE RA (Debería imprimir "ra\n")
    printf("Acción esperada: ra\n");
    ra(&a); 
    print_circular_stack(a, "A"); // Resultado: 20 30 10
    printf("\n");

    // 3. PRUEBA DE RR (Debería imprimir "rr\n" y NADA MÁS)
    printf("Acción esperada: rr\n");
    rr(&a, &b); 
    print_circular_stack(a, "A"); // Resultado: 30 10 20
    print_circular_stack(b, "B"); // Resultado: 200 100
    printf("\n");

    // 4. PRUEBA DE RB (Debería imprimir "rb\n")
    printf("Acción esperada: rb\n");
    rb(&b);
    print_circular_stack(b, "B"); // Resultado: 100 200

    return (0);
}