/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:43:03 by ffleitas          #+#    #+#             */
/*   Updated: 2024/05/21 21:11:02 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_error(char *argv)
{
	if (*argv == '-' || *argv == '+')
		argv ++;
	while (*argv)
	{
		if (!ft_isdigit(*argv))
			return (1);
		argv ++;
	}
	return (0);
}

int	repeated_numbers(t_node *stack_a, int number)
{
	t_node	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->val == number)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	*stack = NULL;
}

void	free_error(t_node **stack_a)
{
	free_stack(stack_a);
	ft_printf("Error\n");
	exit(0);
}
