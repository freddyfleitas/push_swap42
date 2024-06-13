/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:24:58 by ffleitas          #+#    #+#             */
/*   Updated: 2024/06/13 19:56:26 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	highest_unassigned(t_node *stack, t_node **highest)
{
    t_node *cur;

	cur = stack;
	*highest = NULL;
    while (cur)
    {
		if (!cur->assigned && (!*highest || cur->val > (*highest)->val))
			*highest = cur;
		cur = cur->next;
    }
	if (*highest)
		(*highest)->assigned = true;
}

void    assign_index(t_node *stack)
{
	t_node *highest;
    int len;

    len = stack_len(stack);
	highest = NULL;
    while (stack && len > 0)
    {
        highest_unassigned(stack, &highest);
        if (highest)
            highest->index = len;
        len --;
    }
}

void	current_index(t_node *stack)
{
	int	i;
	t_node	*current;

	i = 0;
	current = stack;
	while (current)
	{
		current->current_index = i;
		current = current->next;
		i ++;
	}
}