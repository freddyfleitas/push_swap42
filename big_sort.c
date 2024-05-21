/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:14:12 by ffleitas          #+#    #+#             */
/*   Updated: 2024/05/21 21:06:20 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target(t_node *stack_a, t_node *stack_b)
{
	t_node	*target_node;
	t_node	*current_a;
	long	match;

	while (stack_b)
	{
		match = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->val > stack_b->val && current_a->val < match)
			{
				match = current_a->val;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (match == LONG_MAX)
			stack_b->target = find_lowest(stack_a);
		else
			stack_b->target = target_node;
		stack_b = stack_b->next;
	}
}

static void	set_price(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_b)
	{
		stack_b->price = stack_b->index;
		if (!stack_b->above_midpoint)
			stack_b->price = len_b - (stack_b->index);
		if (stack_b->target->above_midpoint)
			stack_b->price += stack_b->target->index;
		else
			stack_b->price += len_a - (stack_b->target->index);
		stack_b = stack_b->next;
	}
}

static void	set_cheapest(t_node *stack_b)
{
	t_node	*cheapest;
	long	match;

	match = LONG_MAX;
	while (stack_b)
	{
		if (stack_b->price < match)
		{
			match = stack_b->price;
			cheapest = stack_b;
		}
		stack_b = stack_b->next;
	}
	cheapest->cheapest = true;
}

static void	init_nodes(t_node *stack_a, t_node *stack_b)
{
	stack_index(stack_a);
	stack_index(stack_b);
	set_target(stack_a, stack_b);
	set_price(stack_a, stack_b);
	set_cheapest(stack_b);
}

void	big_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*lowest;

	while (stack_len(*stack_a) > 3 && !stack_sorted(*stack_a))
		pb (stack_a, stack_b, 1);
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes (*stack_a, *stack_b);
		move_nodes (stack_a, stack_b);
	}
	stack_index(*stack_a);
	lowest = find_lowest(*stack_a);
	while (*stack_a != lowest)
	{
		if (lowest->above_midpoint)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
}
