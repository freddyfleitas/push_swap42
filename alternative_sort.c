/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alternative_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:15:21 by ffleitas          #+#    #+#             */
/*   Updated: 2024/05/26 18:09:37 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void highest_unassigned(t_node **stack)
{
    t_node *current;
    long    placeholder;

    current = *stack;
    placeholder = LONG_MAX;
    while (current)
    {
        
    }
}

void    assign_index(t_node *stack)
{
    int len;

    len = stack_len(stack);
    while (stack && len > 0)
    {
        highest_unassigned(&stack);
        if (stack->assigned)
            stack->index = len;
        len --;
    }
}

