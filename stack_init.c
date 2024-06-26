/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:50:07 by ffleitas          #+#    #+#             */
/*   Updated: 2024/05/21 21:27:22 by ffleitas         ###   ########.fr       */
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

static void	append_node(t_node **stack_a, int number)
{
	t_node	*new_node;
	t_node	*last_node;

	if (!stack_a)
		return ;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->val = number;
	new_node->next = NULL;
	if (!*stack_a)
	{
		*stack_a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = *stack_a;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	stack_init(t_node **stack_a, char **argv)
{
	long int	number;

	while (*argv)
	{
		if (syntax_error(*argv))
			free_error(stack_a);
		number = ft_atol(*argv);
		if (number > INT_MAX || number < INT_MIN)
			free_error(stack_a);
		if (repeated_numbers(*stack_a, (int)number))
			free_error(stack_a);
		append_node(stack_a, (int)number);
		argv ++;
	}
}
