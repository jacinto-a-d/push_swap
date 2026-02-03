/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabad-di <jabad-di@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:26:48 by jabad-di          #+#    #+#             */
/*   Updated: 2026/02/03 18:59:23 by jabad-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *tmp;

    stack_a = NULL;
    if (argc < 2)
        return (0);
    
    stack_a = init_stack(&stack_a, argv);
    if (!stack_a) // Siempre protege por si init_stack falla
        return (0);

    // 1. Imprimimos el primer nodo manualmente
    tmp = stack_a;
    printf("Nodo: %d (index: %d)\n", tmp->value, tmp->index);
    
    // 2. Movemos tmp al segundo nodo
    tmp = tmp->next;

    // 3. El bucle se detiene cuando vuelve a ser el inicio
    while (tmp != stack_a)
    {
        printf("Nodo: %d (index: %d)\n", tmp->value, tmp->index);
        tmp = tmp->next;
    }

    free_stack(&stack_a);
    return (0);
}