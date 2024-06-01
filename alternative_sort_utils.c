/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alternative_sort_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:06:01 by ffleitas          #+#    #+#             */
/*   Updated: 2024/06/01 20:23:17 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	highest_unassigned(t_node *stack, t_node **highest)
{
    t_node *cur;

	cur = stack;
	*highest = NULL;
    while (cur)
    {
		if (!cur->assigned && (!*highest || cur->val > (*highest)->val))
			*highest = cur;
		cur = cur->next;
    }
	if (*highest)
		(*highest)->assigned = true;
}

void    assign_index(t_node *stack)
{
	t_node *highest;
    int len;

    len = stack_len(stack);
	highest = NULL;
    while (stack && len > 0)
    {
        highest_unassigned(stack, &highest);
        if (highest)
            highest->index = len;
        len --;
    }
}

void	current_index(t_node *stack)
{
	int	i;
	int	midpoint;

	i = 0;
	midpoint = stack_len(stack) / 2;
	if (!stack)
		return ;
	while (stack)
	{
		stack->current_index = i;
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

bool	is_sorted(t_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (false);
		stack = stack->next;
	}
	return (true);
}