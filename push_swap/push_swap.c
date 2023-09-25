/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma <buryilma@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:58:29 by buryilma          #+#    #+#             */
/*   Updated: 2023/09/25 19:06:45 by buryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	int		j;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac > 1)
	{
		stack_a = NULL;
		stack_b = NULL;
		j = 1;
		ft_control(stack_a, av, j);
		ft_push_loop(&stack_a, av, j, ac);
		ft_is_one(&stack_a, &stack_b);
		if (check_sort(stack_a) == 1)
		{
			free_stack(stack_a);
			free_stack(stack_b);
			exit(0);
		}
		ft_sort(&stack_a, &stack_b, ft_stacksize(stack_a));
		free_stack(stack_a);
		free_stack(stack_b);
	}
	return (0);
}
