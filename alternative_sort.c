/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alternative_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:15:21 by ffleitas          #+#    #+#             */
/*   Updated: 2024/06/02 02:05:51 by ffleitas         ###   ########.fr       */
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

static void push_to_b(t_node **stack_a, t_node **stack_b) REVISAR LA FUNCIÓN
{
    t_node *a;
    t_node *b;
    int len;
    int pushed;

    a = *stack_a;
    b = *stack_b;
    len = stack_len(a);
    pushed = 0;
    
    while (stack_len(a) > 3 && pushed < len / 2)
    {
        if (a->index <= len / 2)
        {
            pb(&a, &b, 1);
            pushed++;
        }
        else
            ra(&a, 1);
    }
    
    while (stack_len(a) > 3)
        pb(&a, &b, 1);
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
