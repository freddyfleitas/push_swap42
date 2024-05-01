/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:34:05 by freddy            #+#    #+#             */
/*   Updated: 2024/05/01 11:16:46 by ffleitas         ###   ########.fr       */
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
    t_node  *highest;
    t_node  *lowest;
    
    if (stack_len(*stack_a) > 3)
    {
        pb(stack_a, stack_b, 1);
        pb(stack_a, stack_b, 1);
    }
    lowest = find_lowest(*stack_b);
    highest = find_highest(*stack_b);
    printf("Lowest: %ld\n", lowest->val);
    printf("Highest: %ld\n", highest->val);
}