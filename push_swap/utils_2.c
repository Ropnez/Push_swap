/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma <buryilma@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 22:58:29 by buryilma          #+#    #+#             */
/*   Updated: 2023/09/25 19:08:08 by buryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"
#include <unistd.h>

void	ft_error(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = (stack)->next;
		free(tmp);
	}
	write(2, "Error\n", 6);
	exit(0);
}

void	ft_control(t_stack *stack_a, char **av, int j)
{
	if (av[1][0] == '\0')
		ft_error(stack_a);
	if (av[1][0] == ' ' && av[1][1] == '\0')
		ft_error(stack_a);
	if (ft_strlen(av[1]) == 0)
		ft_error(stack_a);
	while (av[j])
	{
		control(av[j]);
		j++;
	}
}

void	space_ctrl(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			j++;
		i++;
	}
	if (j == 0)
		ft_error(NULL);
}

int	control(char *str)
{
	int	i;

	i = 0;
	space_ctrl(str);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9'
			&& str[i + 1] == '-' && str[i + 2] >= '0' && str[i + 2] <= '9')
			ft_error(NULL);
		else if (str[i] >= '0' && str[i] <= '9'
			&& str[i + 1] == '+' && str[i + 2] >= '0' && str[i + 2] <= '9')
			ft_error(NULL);
		else if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
			i++;
		else if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
			i++;
		else if (str[i] == ' ')
			i++;
		else
			ft_error(NULL);
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
			return (0);
		}
		j++;
	}
	free(arr);
	return (1);
}
