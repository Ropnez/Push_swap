#include "push_swap.h"
#include <unistd.h>

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (stacksize(*stack_a) > 0){
		push(stack_b, (*stack_a)->data);
		pop(stack_a);
		write(1, "pb\n", 3);
	}
}

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	temp = (*stack);
	last = (*stack);
	while (last->next)
		last = last->next;
	last->next = temp;
	temp = temp ->next;
	last ->next->next = NULL;
	(*stack) = temp;
}

void	ra(t_stack **stack_a)
{
	if (stacksize(*stack_a) > 0)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack **stack_b)
{
	if (stacksize(*stack_b) > 0)
	{
		rotate(stack_b);
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (stacksize(*stack_a) > 0 && stacksize(*stack_b) > 0)
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
	}
}