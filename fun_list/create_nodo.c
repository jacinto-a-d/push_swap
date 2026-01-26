#include "push_swap.h"
#include "printf/ft_printf.h"

t_stack	*create_nodo(void *value)
{
	t_stack	*nodo;

	nodo = malloc(sizeof(t_stack));
	if (!nodo)
		return(NULL);
	nodo->value = value;
	nodo->next = NULL;
	return (nodo);
}