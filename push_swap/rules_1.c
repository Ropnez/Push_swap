/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma <buryilma@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:40:29 by buryilma          #+#    #+#             */
/*   Updated: 2023/09/25 18:57:56 by buryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	sa(t_stack **stack_a, int print)
{
	if (ft_stacksize(*stack_a) > 1)
	{
		swap(stack_a);
		if (print == 1)
			write(1, "sa\n", 3);
	}
}

void	sb(t_stack **stack_b, int print)
{
	if (ft_stacksize(*stack_b) > 1)
	{
		swap(stack_b);
		if (print == 1)
			write(1, "sb\n", 3);
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	if (ft_stacksize(*stack_a) > 1 && ft_stacksize(*stack_b) > 1)
	{
		swap(stack_a);
		swap(stack_b);
		if (print == 1)
			write(1, "ss\n", 3);
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	if (ft_stacksize(*stack_b) > 0)
	{
		push(stack_a, (*stack_b)->data);
		pop(stack_b);
		if (print == 1)
			write(1, "pa\n", 3);
	}
}
