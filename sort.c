/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:15:21 by ffleitas          #+#    #+#             */
/*   Updated: 2024/06/10 19:24:22 by ffleitas         ###   ########.fr       */
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

static int	get_lowest(t_node *stack_a, int holder)
{
	t_node	*cur_a;
	int		lowest_index;

	cur_a = stack_a;
	lowest_index = 0;
	while (cur_a)
	{
		if (cur_a->index < holder)
		{
			holder = cur_a->index;
			lowest_index = cur_a->current_index;
		}
		cur_a = cur_a->next;
	}
	return (lowest_index);
}


static int get_target(t_node *stack_a, int index_b, int holder, int target)
{
	t_node	*cur_a;

	cur_a = stack_a;

	target = 0;
	// Target: should be the closest_larger;
	while (cur_a)
	{
		if (cur_a->index > index_b && cur_a->index < holder)
		{
			holder = cur_a->index;
			target = cur_a->current_index;
		}
		cur_a = cur_a->next;
	}
	if (holder != INT_MAX)
		return (target);
	else
		return (get_lowest(stack_a, holder));
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
		target = get_target(stack_a, cur_b->index, INT_MAX);
		cur_b->target_index = target;
		printf("Target for index %d is: %d\n", cur_b->index, target);
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
		*stack_b = (*stack_b)->next;
		// assign_price(*stack_a, *stack_b);
		// push_to_a(stack_a, stack_b);
	}
	// if (!is_sorted(*stack_a))
	// 	finish_sort(stack_a); 
}
