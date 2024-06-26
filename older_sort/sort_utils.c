/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:36:15 by freddy            #+#    #+#             */
/*   Updated: 2024/05/21 21:24:00 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_index(t_node *stack)
{
	int	i;
	int	midpoint;

	i = 0;
	midpoint = stack_len(stack) / 2;
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = i;
		if (i <= midpoint)
			stack->above_midpoint = true;
		else
			stack->above_midpoint = false;
		stack = stack->next;
		i ++;
	}
}

int	stack_len(t_node *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_node	*find_highest(t_node *stack)
{
	t_node	*highest;

	if (!stack)
		return (NULL);
	highest = stack;
	while (stack)
	{
		if (stack->val > highest->val)
			highest = stack;
		stack = stack->next;
	}
	return (highest);
}

t_node	*find_lowest(t_node *stack)
{
	t_node	*lowest;

	if (!stack)
		return (NULL);
	lowest = stack;
	while (stack)
	{
		if (stack->val < lowest->val)
			lowest = stack;
		stack = stack->next;
	}
	return (lowest);
}
