

// EL HEADER

#include "push_swap.h"

static void	add_to_dest(t_stack **dest, t_stack *node)
{
	t_stack		*last_node;
	
	last_node = (*dest)->prev;
	node->next = *dest;
	node->prev = last_node;
	last_node->next = node;
	(*dest)->prev = node;
	*dest = node;
}

static int	push(t_stack **dest, t_stack **src)
{
	t_stack		*node;

	if (!src || !*src)
		return (0);
	node = *src;
	if ((*src)->next == *src)
		*src = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		*src = node->next;
	}
	if (!dest || !*dest)
	{
		*dest = node;
		node->next = node;
		node->prev = node;
	}
	else
		add_to_dest(dest, node);
	return (1);
}

void	pa(t_stack **a, t_stack **b)
{
	if (push(a, b))
	write (1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a)
{
	if (push(b, a))
	write (1, "pb\n", 3);
}
