
#include <stdio.h>
#include "push_swap.h"




void	check_duplicates(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*checker;

	current = stack_a;
	while (current != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->value == checker->value)
			{
				ft_putstr_fd("Error\n", 2);
				exit (1);
			}
			checker = checker->next;
		}
		current = current->next;
	}
}

void	format_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+'
			&& str[i] != ' ')
		{
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
		i++;
	}
}

void	check_num(int argc, char **argv)
{
	char	**str;

	if (argc == 2)
		str = ft_split(argv[1], ' ');
	else if (argc > 2)
		str = &argv[1];
	else
		return ;
}

void	init_stack(t_stack *stack_a, char *str)
{
	int	i;
	long	num;
	
	i = 0;
	num = 0;
	if (str[i] != '\0')
	{
		format_valid(str[i]);
	}
	num = ft_atoi_long(str[i]);
	check_int(num);
}
