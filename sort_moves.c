/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:25:07 by ffleitas          #+#    #+#             */
/*   Updated: 2024/06/12 21:33:46 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rr_both (t_node **stack_a, t_node **stack_b, int *cost_a, 
        int *cost_b)
{
    while (*cost_a < 0 && *cost_b < 0)
    {
        rrr(stack_a, stack_b, 1);
        (*cost_a)++;
        (*cost_b)++;
    }
}

static  void r_both (t_node **stack_a, t_node **stack_b, int *cost_a, 
        int *cost_b)
{
    while (*cost_a > 0 && *cost_b > 0)
    {
        rr(stack_a, stack_b, 1);
        (*cost_a)--;
        (*cost_b)--;
    }
}

static void rotate_a(t_node **stack_a, int *cost)
{
    while (*cost)
    {
        if (*cost > 0)
        {
            ra(stack_a, 1);
            (*cost)--;
        }
        else
        {
            rra(stack_a, 1);
            (*cost)++;
        }
    }
}

static void rotate_b(t_node **stack_b, int *cost)
{
    while (*cost)
    {
        if (*cost > 0)
        {
            rb(stack_b, 1);
            (*cost)--;
        }
        else
        {
            rrb(stack_b, 1);
            (*cost)++;
        }
    }
}

void    move_nodes(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b)
{
    if (cost_a < 0 && cost_b < 0)
        rr_both(stack_a, stack_b, &cost_a, &cost_b);
    else if (cost_a > 0 && cost_b > 0)
        r_both (stack_a, stack_b, &cost_a, &cost_b);
    rotate_a(stack_a, &cost_a);
    rotate_b(stack_b, &cost_b);
    pa(stack_a, stack_b, 1);
}