/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma <buryilma@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:58:29 by buryilma          #+#    #+#             */
/*   Updated: 2023/09/25 19:00:11 by buryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	if (ft_stacksize(*stack_a) > 0)
	{
		push(stack_b, (*stack_a)->data);
		pop(stack_a);
		if (print == 1)
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

void	ra(t_stack **stack_a, int print)
{
	if (ft_stacksize(*stack_a) > 0)
	{
		rotate(stack_a);
		if (print == 1)
			write(1, "ra\n", 3);
	}
}

void	rb(t_stack **stack_b, int print)
{
	if (ft_stacksize(*stack_b) > 0)
	{
		rotate(stack_b);
		if (print == 1)
			write(1, "rb\n", 3);
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	if (ft_stacksize(*stack_a) > 0 && ft_stacksize(*stack_b) > 0)
	{
		rotate(stack_a);
		rotate(stack_b);
		if (print == 1)
			write(1, "rr\n", 3);
	}
}
