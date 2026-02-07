

// EL HEADDER


#include "push_swap.h"

t_stack *find_cheapest(t_stack *stack)
{
    t_stack *cheapest_node;
    t_stack *start;
    long    best_value;

    if (!stack)
        return (NULL);
    
    start = stack;
    best_value = 2147483648LL; // Valor mayor que INT_MAX
    cheapest_node = NULL;

    while (1)
    {
        if (stack->push_cost < best_value)
        {
            best_value = stack->push_cost;
            cheapest_node = stack;
        }
        stack = stack->next;
        if (stack == start)
            break;
    }
    return (cheapest_node);
}