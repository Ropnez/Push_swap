#include "push_swap.h"
#include <unistd.h>

void	swap(t_stack **stack)
{
	t_stack	*temp;

	temp = (*stack)-> next;
	(*stack)->next = temp ->next;
	temp->next = (*stack);
	(*stack) = temp;
}

void	sa(t_stack **stack_a)
{
	if (stacksize(*stack_a) > 1)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack **stack_b)
{
	if (stacksize(*stack_b) > 1)
	{
		swap(stack_b);
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (stacksize(*stack_a) > 1 && stacksize(*stack_b) > 1)
	{
		swap(stack_a);
		swap(stack_b);
		write(1, "ss\n", 3);
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (stacksize(*stack_b) > 0){
		push(stack_a, (*stack_b)->data);
		pop(stack_b);
		write(1, "pa\n", 3);
	}
}
