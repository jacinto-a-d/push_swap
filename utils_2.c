

// EL HEADDER


#include "push_swap.h"

t_stack *find_cheapest(t_stack *stack)
{
    t_stack *cheapest_node;
    t_stack *tmp;
    long    best_value;

    if (!stack)
        return (NULL);
    
    tmp = stack;
    best_value = 2147483648; 
    cheapest_node = NULL;

    while (1)
    {
        if (stack->push_cost < best_value)
        {
            best_value = stack->push_cost;
            cheapest_node = stack;
        }
        stack = stack->next;
        if (tmp == stack)
            break;
    }
    return (cheapest_node);
}