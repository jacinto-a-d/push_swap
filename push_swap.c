
#include "printf/ft_printf.h"
#include "push_swap.h"


int		list_size_circular(t_stack *stack)
{
	t_stack	*ptr;
	int		i;

	i = 1;
	ptr = stack->next;
	if(!ptr)
		return(0);
	while(ptr != stack->next)
	{
		i++;
		ptr = ptr->next;
	}
	return(i);
}

void	*init_stack(t_stack **stack_a,char **argv)
{
	char	*tmp;
	long	num;
	int		i;
	int		x;
	int		result;
	
	i = 0;
	x = 0;
	num = 0;
	result = 0;
	while(argv[i])
	{
		tmp = ft_split(argv[i], ' ');
		while(tmp[x])
		{
			num = atoi_long(argv[i]);
			result = check_int(num);
			// crear nodo y anadir a la lista circular
			free(tmp[x]);
			x++;
		}
		i++;
	}
	free(tmp);
}
