/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:56:30 by ffleitas          #+#    #+#             */
/*   Updated: 2024/04/19 17:17:11 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void swap(t_node **head)
{	
	t_node *tmp;
	
	if (!*head || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = tmp;
	(*head)->next = tmp;
	(*head)->prev = NULL;
}

void	sa(t_node **stack_a, int print)
{
	swap(stack_a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_node **stack_b, int print)
{
	swap(stack_b);
	if (print)
		ft_printf("sb\n");
}

void ss(t_node **stack_a, t_node **stack_b, int print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		ft_printf("ss\n");
}