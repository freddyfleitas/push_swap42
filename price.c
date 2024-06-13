/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:30:56 by ffleitas          #+#    #+#             */
/*   Updated: 2024/06/13 22:14:01 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    assign_price(t_node *stack_a, t_node *stack_b)
{
    t_node  *cur_b;
    int     len_a;
    int     len_b;

    cur_b = stack_b;
    len_a = stack_len(stack_a);
    len_b = stack_len(stack_b);    
    while (cur_b)
    {
        cur_b->cost_b = cur_b->current_index;
        if (cur_b->current_index > len_b / 2)
            cur_b->cost_b = (len_b - cur_b->current_index) * -1; 
            //Se multiplica por -1 para representar a través de un valor negativo, 
            // que el movimiento debe realizarse hacía atrás
        cur_b->cost_a = cur_b->target_index;
        if (cur_b->target_index > len_a / 2)
            cur_b->cost_a = (len_a - cur_b->target_index) * -1;
        cur_b = cur_b->next;
    }
}

void    cheapest_move(t_node **stack_a, t_node **stack_b)
{
    t_node *cur_b;
    int    cheapest;
    int    cost_a;
    int    cost_b;
    
    cur_b = *stack_b;
    cheapest = INT_MAX;
    while (cur_b)
    {
        if (ft_abs(cur_b->cost_a) + ft_abs(cur_b->cost_b) < cheapest)
        {
            cheapest = ft_abs(cur_b->cost_a) + ft_abs(cur_b->cost_b);
            cost_a = cur_b->cost_a;
            cost_b = cur_b->cost_b;
        }
        cur_b = cur_b->next;
    }
    move_nodes(stack_a, stack_b, cost_a, cost_b);
}



