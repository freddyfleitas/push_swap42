/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:58:30 by ffleitas          #+#    #+#             */
/*   Updated: 2024/04/19 17:16:40 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void reverse_rotate(t_node **head)
{
	t_node *last;
	t_node *first;

	if (!*head || !(*head)->next)
		return ;
	last = find_last(*head);
	first = *head;
	*head = last;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
}

void rra(t_node **stack_a, int print)
{
	reverse_rotate(stack_a);
	if (print)
		ft_printf("rra\n");
}

void rrb(t_node **stack_b, int print)
{
	reverse_rotate(stack_b);
	if (print)
		ft_printf("rrb\n");
}

void rrr(t_node **stack_a, t_node **stack_b, int print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		ft_printf("rrr\n");
}
