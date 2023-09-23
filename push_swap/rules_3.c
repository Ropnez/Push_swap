#include "push_swap.h"
#include <unistd.h>

void	rotate_reverse(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	temp = (*stack);
	last = (*stack);
	while (last->next)
		last = last->next;
	while (temp->next->next != NULL)
		temp = temp->next;
	last->next = (*stack);
	temp->next = NULL;
	(*stack) = last;
}

void	rra(t_stack **stack_a)
{
	if (stacksize(*stack_a) > 1)
	{
		rotate_reverse(stack_a);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **stack_b)
{
	if (stacksize(*stack_b) > 1)
	{
		rotate_reverse(stack_b);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (stacksize(*stack_a) && stacksize(*stack_b))
	{
		rotate_reverse(stack_a);
		rotate_reverse(stack_b);
		write(1, "rrr\n", 4);
	}
}
