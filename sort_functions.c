/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:34:05 by freddy            #+#    #+#             */
/*   Updated: 2024/05/12 15:12:01 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool    stack_sorted(t_node *stack)
{
    if (!stack)
        return (true);
    while (stack->next)
    {
        if (stack->val > stack->next->val)
            return (false);
        stack = stack->next;
    }
    return (true);
}

void    sort_three(t_node **stack)
{
    t_node *highest;

    highest = find_highest(*stack);
    if (highest == *stack)
        ra(stack, 1);
    else if (highest == (*stack)->next)
        rra(stack, 1);
    if ((*stack)->val > (*stack)->next->val)
        sa(stack, 1);
}

void    sort_stacks(t_node **stack_a, t_node **stack_b)
{
    int midpoint;
    
    while(stack_len(*stack_a) > 3)
        pb(stack_a, stack_b, 1);
    if (!stack_sorted(*stack_a))
        sort_three(stack_a);
    stack_index(*stack_a);
    stack_index(*stack_b);
    midpoint = (stack_len(*stack_b) / 2);
    
}