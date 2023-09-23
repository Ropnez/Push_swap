#include <stdlib.h>
#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->data);
		stack = stack->next;
	}
}

void	ft_push_str(t_stack **stack, char *str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(str, ' ');
	if (!tab)
		ft_error(*stack);
	while (tab[i])
	{
		if (check(*stack, ft_atoi(tab[i])) == 0)
		{
			free_tab(tab);
			ft_error(*stack);
		}
		push_init(stack, ft_atoi(tab[i]));
		i++;
	}
	free_tab(tab);
}

void	ft_push_normal(t_stack **stack, char *str)
{
	if (check(*stack, ft_atoi(str)) == 0)
		ft_error(*stack);
	push_init(stack, ft_atoi(str));
}

void	ft_push_loop(t_stack **stack_a, char **av, int j, int ac)
{
	int	i;

	i = 0;
	while (av[j] && ac > 1)
	{
		while (av[j])
		{
			if (av[j][i] != ' ')
				i++;
			else
			{
				ft_push_str(stack_a, av[j]);
				ac--;
				break ;
			}
			if (av[j][i] == '\0')
			{
				ft_push_normal(stack_a, av[j]);
				j++;
				ac--;
				i = 0;
			}
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	int		j;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac > 1)
	{
		stack_a = NULL;
		stack_b = NULL;
		j = 1;
		ft_control(stack_a, av, j);
		ft_push_loop(&stack_a, av, j, ac);
		ft_is_one(&stack_a, &stack_b);
		if (check_sort(stack_a) == 1)
		{
			free_stack(stack_a);
			free_stack(stack_b);
			exit(0);
		}
		print_stack(stack_a);
		free_stack(stack_a);
		free_stack(stack_b);
	}
	return (0);
}

//29 dolap