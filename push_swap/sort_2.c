/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma <buryilma@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:58:29 by buryilma          #+#    #+#             */
/*   Updated: 2023/09/25 18:59:58 by buryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a_i(t_stack **a, t_stack **b, int len)
{
	while (len != 3 || !((*a)->data < (*a)->next->data
			&& (*a)->next->data < (*a)->next->next->data))
	{
		if (len == 3 && (*a)->data > (*a)->next->data
			&& (*a)->next->next->data)
			sa(a, 1);
		else if (len == 3 && !((*a)->next->next->data > (*a)->data
				&& (*a)->next->next->data > (*a)->next->data))
		{
			pb(a, b, 1);
			len--;
		}
		else if ((*a)->data > (*a)->next->data)
			sa(a, 1);
		else if (len++)
			pa(a, b, 1);
	}
}

void	sort_three_a(t_stack **a, t_stack **b, int len)
{
	if (len == 3 && ft_stacksize(*a) == 3)
		sort_three_first(a);
	else if (len == 2)
	{
		if ((*a)->data > (*a)->next->data)
			sa(a, 1);
	}
	else if (len == 3)
	{
		sort_three_a_i(a, b, len);
	}
}

void	sort_small_b_i(t_stack **b, t_stack **a, int len)
{
	while (len || !((*a)->data < (*a)->next->data
			&& (*a)->next->data < (*a)->next->next->data))
	{
		if (len == 1 && (*a)->data > (*a)->next->data)
			sa(a, 1);
		else if ((len == 1
				|| (len >= 2
					&& (*b)->data > (*b)->next->data)
				|| (len == 3
					&& (*b)->data > (*b)->next->next->data)))
		{
			pa(a, b, 1);
			len--;
		}
		else
			sb(b, 1);
	}
}

void	sort_small_b(t_stack **b, t_stack **a, int len)
{
	if (len == 1)
		pa(a, b, 1);
	else if (len == 2)
	{
		if ((*b)->data < (*b)->next->data)
			sb(b, 1);
		while (len--)
			pa(a, b, 1);
	}
	else if (len == 3)
	{
		sort_small_b_i(b, a, len);
	}
}
