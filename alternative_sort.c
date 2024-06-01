/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alternative_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:15:21 by ffleitas          #+#    #+#             */
/*   Updated: 2024/06/01 20:33:43 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_positions(t_node *stack_a, t_node *stack_b)
{
	t_node	*cur_b;
	int		target;

	current_index(stack_a);
	current_index(stack_b);
	cur_b = stack_b;
	target = 0;
	while (cur_b)
	{
		target = get_target(stack_a, stack_b);
		cur_b->target_index = target;
		cur_b = cur_b->next;
	}
}
void	sort_three(t_node *stack)
{
	if (stack->index > stack->next->index
		&&	stack->index > stack->next->next->index)
		ra(&stack, 1);
	else if (stack->next->index > stack->index
		&&	stack->next->index > stack->next->next->index)
		rra(&stack, 1);
	if (stack->index > stack->next->index)
		sa(&stack, 1);
}
void	sort_stacks(t_node **stack_a, t_node **stack_b)
{
	t_node *lowest;
	
	push_to_b(stack_a, stack_b); //Finish this
	sort_three(stack_a);
	while (*stack_b)
	{
		init_positions(*stack_a, *stack_b);
		assign_price(*stack_a, *stack_b);
		push_to_a(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		finish_sort(stack_a);
}
