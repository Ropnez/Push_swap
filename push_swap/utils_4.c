/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma <buryilma@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:04:08 by buryilma          #+#    #+#             */
/*   Updated: 2023/09/25 19:08:18 by buryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	ft_push_str(t_stack **stack, char *str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(str, ' ');
	if (!tab)
		ft_error(*stack);
	while (tab[i])
	{
		if (check(*stack, ft_atoi(tab[i])) == 0)
		{
			free_tab(tab);
			ft_error(*stack);
		}
		push_init(stack, ft_atoi(tab[i]));
		i++;
	}
	free_tab(tab);
}

void	ft_push_normal(t_stack **stack, char *str)
{
	if (check(*stack, ft_atoi(str)) == 0)
		ft_error(*stack);
	push_init(stack, ft_atoi(str));
}

void	ft_push_loop(t_stack **stack_a, char **av, int j, int ac)
{
	int	i;

	i = 0;
	while (av[j] && ac > 1)
	{
		while (av[j])
		{
			if (av[j][i] != ' ')
				i++;
			else
			{
				ft_push_str(stack_a, av[j]);
				ac--;
				break ;
			}
			if (av[j][i] == '\0')
			{
				ft_push_normal(stack_a, av[j]);
				j++;
				ac--;
				i = 0;
			}
		}
		j++;
	}
}
