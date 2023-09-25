/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma <buryilma@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:24:35 by buryilma          #+#    #+#             */
/*   Updated: 2023/09/25 18:56:50 by buryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	free_error(char *rule, t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!(*a) && !(*b))
		return ;
	while (*a)
	{
		temp = (*a);
		(*a) = (*a)->next;
		free(temp);
	}
	while (*b)
	{
		temp = (*b);
		(*b) = (*b)->next;
		free(temp);
	}
	free(rule);
	rule = NULL;
	write(2, "Error\n", 6);
	exit(1);
}

void	run_rules(char *rule, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(rule, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(rule, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(rule, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(rule, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(rule, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(rule, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(rule, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(rule, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(rule, "rrr\n"))
		rrr(a, b, 0);
	else if (!ft_strcmp(rule, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(rule, "pb\n"))
		pb(a, b, 0);
	else
		free_error(rule, a, b);
}

void	ft_instructions(t_stack **a, t_stack **b)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		run_rules(str, a, b);
		free(str);
		str = NULL;
		str = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	int		j;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		j = 1;
		ft_control(stack_a, av, j);
		ft_push_loop(&stack_a, av, j, ac);
		ft_instructions(&stack_a, &stack_b);
		if (is_sorted(&stack_a, 'a', ft_stacksize(stack_a)))
			write(1, "OK\n", 3);
		else
			write(2, "KO\n", 3);
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
