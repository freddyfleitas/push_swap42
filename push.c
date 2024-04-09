/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:56:24 by ffleitas          #+#    #+#             */
/*   Updated: 2024/04/09 22:51:33 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **src, t_node **dst)
{
	t_node *push_node;
	
	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		push_node->next = NULL;
		*dst = push_node;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_node **stack_a, t_node **stack_b, int print)
{
	push(stack_a, stack_b);
	if (!print)
		ft_printf("pa\n");	
}

void	pb(t_node **stack_a, t_node **stack_b, int print)
{
	push(stack_b, stack_a);
	if (!print)
		ft_printf("pb\n");	
}