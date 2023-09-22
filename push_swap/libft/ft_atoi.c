/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma <buryilma@42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:13:28 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/22 01:51:09 by buryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"


int	ft_atoi(const char *str)
{
	int	sign;
	long result;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (*str == '-' || *str == '+')
		return (0);
	if (!(*str >= '0' && *str <= '9'))
		ft_error(NULL);
	while (ft_isdigit(*str) == 1)
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	result *= sign;
	if (result > 2147483647 || result < -2147483647)
		ft_error(NULL);
	return (result);
}
