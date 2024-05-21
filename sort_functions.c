/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:34:05 by freddy            #+#    #+#             */
/*   Updated: 2024/05/21 18:19:01 by ffleitas         ###   ########.fr       */
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
    if (!stack_sorted(*stack))
    {
        if (highest == *stack)
            ra(stack, 1);
        else if (highest == (*stack)->next)
            rra(stack, 1);
        if ((*stack)->val > (*stack)->next->val)
            sa(stack, 1);
    }
}

void   sort_five(t_node **stack_a, t_node **stack_b)
{
    t_node *lowest;

    while (stack_len(*stack_a) > 3)
    {
        stack_index(*stack_a);
        lowest = find_lowest(*stack_a);
        if (lowest->index == 0)
            pb (stack_a, stack_b, 1);
        else
        {
            if (lowest->above_midpoint)
                ra(stack_a, 1);
            else
                rra(stack_a, 1);   
        }
    }
    sort_three(stack_a);
    while (*stack_b)
        pa(stack_a, stack_b, 1);
}