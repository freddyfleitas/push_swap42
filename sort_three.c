/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:11:08 by ffleitas          #+#    #+#             */
/*   Updated: 2024/06/13 20:53:48 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack)
{
    if ((*stack)->index > (*stack)->next->index
		&& (*stack)->index > (*stack)->next->next->index)
		ra(stack, 1);
	else if ((*stack)->next->index > (*stack)->index
		&& (*stack)->next->index > (*stack)->next->next->index)
		rra(stack, 1);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack, 1);   
}