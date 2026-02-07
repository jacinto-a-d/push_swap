

// EL HEADERRR

#include "push_swap.h"

static int	swap(t_stack **stack)
{
	int		tmp;
	
	tmp = 0;
	if (!stack || !*stack || (*stack)->next == *stack)
		return (0);
	else
	{
		tmp = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = tmp;
	}
	return (1);
}

void	sa(t_stack **a)
{
	if (swap(a))
		write (1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	if (swap(b))
		write (1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	int		tmp_a;
	int		tmp_b;

	tmp_a = swap(a);
	tmp_b = swap(b);
	if (tmp_a || tmp_b)
		write (1, "ss\n", 3);
}
