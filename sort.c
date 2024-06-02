/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:15:21 by ffleitas          #+#    #+#             */
/*   Updated: 2024/06/02 21:59:31 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void push_to_b(t_node **stack_a, t_node **stack_b)
{
    int len;
    int pushed;
	int counter;

    len = stack_len(*stack_a);
    pushed = 0;
	counter = 0;
    
    while (stack_len(*stack_a) > 3 && counter < len && pushed < len / 2)
    {
        if ((*stack_a)->index <= len / 2)
        {
            pb(stack_a, stack_b, 1);
            pushed++;
        }
        else
            ra(stack_a, 1);
		counter ++;
    }
    while (stack_len(*stack_a) > 3)
        pb(stack_a, stack_b, 1);
}

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

void	sort_stacks(t_node **stack_a, t_node **stack_b)
{
	push_to_b(stack_a, stack_b); 
	sort_three(*stack_a);
	while (*stack_b)
	{
		init_positions(*stack_a, *stack_b);
		// assign_price(*stack_a, *stack_b);
		// push_to_a(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		finish_sort(stack_a); 
}
