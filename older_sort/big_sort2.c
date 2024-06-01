/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:32:20 by ffleitas          #+#    #+#             */
/*   Updated: 2024/05/21 21:10:24 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

static void	r_both(t_node **stack_a, t_node **stack_b, t_node *cheapest)
{
	while (*stack_a != cheapest->target && *stack_b != cheapest)
		rr (stack_a, stack_b, 1);
	stack_index(*stack_a);
	stack_index(*stack_b);
}

static void	rr_both(t_node **stack_a, t_node **stack_b, t_node *cheapest)
{
	while (*stack_a != cheapest->target && *stack_b != cheapest)
		rrr (stack_a, stack_b, 1);
	stack_index(*stack_a);
	stack_index(*stack_b);
}

static void	finish_rotation(t_node **stack, t_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_midpoint)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_midpoint)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}

void	move_nodes(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;

	cheapest = find_cheapest(*stack_b);
	if (cheapest->above_midpoint && cheapest->target->above_midpoint)
		r_both(stack_a, stack_b, cheapest);
	else if (!cheapest->above_midpoint && !cheapest->target->above_midpoint)
		rr_both(stack_a, stack_b, cheapest);
	finish_rotation(stack_b, cheapest, 'b');
	finish_rotation(stack_a, cheapest->target, 'a');
	pa(stack_a, stack_b, 1);
}
