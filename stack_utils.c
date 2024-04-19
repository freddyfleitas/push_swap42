/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:38:00 by ffleitas          #+#    #+#             */
/*   Updated: 2024/04/09 20:37:03 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
	{
		return (1);
	}
	return (0);
}

long int	ft_atol(const char *str)
{
	long int	result;
	int			sign;

	result = 0;
	sign = 1;
	while (isspace(*str))
	{
		str ++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign *= -1;
		}
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str ++;
	}
	return (result * sign);
}