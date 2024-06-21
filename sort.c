/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:15:21 by ffleitas          #+#    #+#             */
/*   Updated: 2024/06/21 19:40:19 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void push_to_b(t_node **stack_a, t_node **stack_b)
{
    int len;
    int pushed;
	int i;

    len = stack_len(*stack_a);
    pushed = 0;
	i = 0;
    
    while (len > 3 && i < len && pushed < len / 2)
    {
        if ((*stack_a)->index <= len / 2)
        {
            pb(stack_a, stack_b, 1);
            pushed++;
        }
        else
            ra(stack_a, 1);
		i ++;
    }
    while (len - pushed > 3)
	{
        pb(stack_a, stack_b, 1);
		pushed ++;
	}
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


static int get_target(t_node *stack_a, int index_b, int holder,
		int target)
{
	t_node	*cur_a;

	cur_a = stack_a;
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
	cur_a = stack_a;
	while (cur_a)
	{
		if (cur_a->index < target)
		{
			holder = cur_a-> index;
			target = cur_a -> current_index;
		}
		cur_a = cur_a->next;
	}
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
		target = get_target(stack_a, cur_b->index, INT_MAX, target);
		cur_b->target_index = target;
		cur_b = cur_b->next;
	}
}

static void finish_sort(t_node **stack_a)
{
    int len;
    int counter;
    t_node *temp;

    len = stack_len(*stack_a);
    counter = 0;
    temp = *stack_a;
    while (temp && temp->index != 1)
    {
        temp = temp->next;
        counter++;
    }
    if (counter > len / 2)
    {
        while (counter < len)
        {
            rra(stack_a, 1); 
            counter++;
        }
    }
    else
    {
        while (counter > 0)
        {
            ra(stack_a, 1); 
            counter--;
        }
    }
}


void	sort_stacks(t_node **stack_a, t_node **stack_b)
{
	push_to_b(stack_a, stack_b); 
	sort_three(stack_a);
	while (*stack_b)
	{
		init_positions(*stack_a, *stack_b);
		assign_price(*stack_a, *stack_b);
		cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		finish_sort(stack_a);
}
