#include "push_swap.h"
#include <stdlib.h>

int	stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = (stack)->next;
		free(tmp);
	}
}

void	ft_is_one(t_stack **stack_a, t_stack **stack_b)
{
	if (stacksize(*stack_a) == 1)
	{
		free_stack(*stack_a);
		free_stack(*stack_b);
		exit(0);
	}
}

int	check_sort(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
