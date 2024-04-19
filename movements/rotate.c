/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:56:28 by ffleitas          #+#    #+#             */
/*   Updated: 2024/04/19 17:17:25 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node *find_last(t_node *head)
{

	if (!head || !head->next)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

static void	rotate(t_node **head)
{
	t_node *last;
	t_node *first;

	if (!*head || !(*head)->next)
		return ;
	last = find_last(*head);
	first = *head; 
	*head = (*head)->next;
	(*head)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;	
}

void ra(t_node **stack_a, int print)
{
	rotate(stack_a);
	if (print)
		ft_printf("ra\n");
}

void rb(t_node **stack_b, int print)
{
	rotate(stack_b);
	if (print)
		ft_printf("rb\n");
}

void rr(t_node **stack_a, t_node **stack_b, int print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		ft_printf("rr\n");
}