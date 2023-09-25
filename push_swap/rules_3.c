/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma <buryilma@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:58:29 by buryilma          #+#    #+#             */
/*   Updated: 2023/09/25 18:58:11 by buryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	rra(t_stack **stack_a, int print)
{
	if (ft_stacksize(*stack_a) > 1)
	{
		rotate_reverse(stack_a);
		if (print == 1)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **stack_b, int print)
{
	if (ft_stacksize(*stack_b) > 1)
	{
		rotate_reverse(stack_b);
		if (print == 1)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	if (ft_stacksize(*stack_a) && ft_stacksize(*stack_b))
	{
		rotate_reverse(stack_a);
		rotate_reverse(stack_b);
		if (print == 1)
			write(1, "rrr\n", 4);
	}
}
