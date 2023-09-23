#include "push_swap.h"
#include <stdlib.h>

#include <stdio.h>

int main(int ac, char **av)
{
    if (ac > 1){
        int j = 1;
        int i = 0;
        t_stack *stack_a = NULL;
        t_stack *stack_b = NULL;
        char **str;
        if (ft_strlen(av[1]) == 0)
            ft_error(stack_a);
        while (av[j]){
            control(av[j]);
            j++;
        }
        j = 1;
        while (av[j] && ac > 1)
        {
            while (av[j])
            {
                if (av[j][i] != ' ')
                    i++;
                else
                {
                    i = 0;
                    str = ft_split(av[j], ' ');
                    if (!str)
                        ft_error(stack_a);
                    while (str[i])
                    {
                        if (check(stack_a, ft_atoi(str[i])) == 0)
                        {
                            free_tab(str);
                            ft_error(stack_a);
                        }
                        push_init(&stack_a, ft_atoi(str[i]));
                        i++;
                    }
                    free_tab(str);
                    ac--;
                    break;
                }
                if (av[j][i] == '\0')
                {
                    if (check(stack_a, ft_atoi(av[j])) == 0)
                        ft_error(stack_a);
                    push_init(&stack_a, ft_atoi(av[j]));
                    j++;
                    ac--;
                    i = 0;
                }
            }
            j++;
        }
        // sa(&stack_a);
        // pb(&stack_a, &stack_b);
        // pb(&stack_a, &stack_b);
        // pb(&stack_a, &stack_b);
        // rr(&stack_a, &stack_b);
        // rrr(&stack_a, &stack_b);
        // sa(&stack_a);
        // pa(&stack_a, &stack_b);
        // pa(&stack_a, &stack_b);
        // pa(&stack_a, &stack_b);
        // while(stack_a){
        //     if (!stack_b){
        //         printf("%d\n", stack_a->data);
        //         stack_a = stack_a->next;
        //     }
        //     else
        //     {
        //         printf("%d ", stack_a->data);
        //         stack_a = stack_a->next;
        //         printf("%d\n", stack_b->data);
        //         stack_b = stack_b->next;
        //     }

        // }

        free_stack(stack_a);
        free_stack(stack_b);
    }
}











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




int	check(t_stack *stack, int data)
{
	int	i;
	int	j;
	int	size;
	int	*arr;

	i = 0;
	j = 0;
	size = stacksize(stack);
	arr = malloc(sizeof(int) * size);
	while (stack)
	{
		arr[i++] = stack->data;
		stack = stack->next;
	}
	while (j < size)
	{
		if (arr[j] == data)
		{
			free(arr);
			return 0;
		}
		j++;
	}
	free(arr);
	return (1);
}