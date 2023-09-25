/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma <buryilma@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:10:29 by buryilma          #+#    #+#             */
/*   Updated: 2023/09/25 18:58:58 by buryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	pop(t_stack **stack)
{
	t_stack	*temp;

	if (!(*stack))
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

void	push(t_stack **stack, int data)
{
	t_stack	*temp;

	temp = malloc(sizeof(t_stack));
	if (!temp)
		ft_error(*stack);
	temp->data = data;
	temp->next = *stack;
	*stack = temp;
}

void	push_init(t_stack **stack, int data)
{
	t_stack	*new;
	t_stack	*tmp;

	if (!(*stack))
	{
		*stack = malloc(sizeof(t_stack));
		if (!(*stack))
			ft_error(*stack);
		(*stack)->data = data;
		(*stack)->next = NULL;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	new = malloc(sizeof(t_stack));
	if (!new)
		ft_error(*stack);
	new->data = data;
	new->next = NULL;
	tmp->next = new;
}
