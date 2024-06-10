/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:51:32 by ffleitas          #+#    #+#             */
/*   Updated: 2024/06/10 19:10:10 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node *stack)
{
	if (stack->index > stack->next->index 
		&& stack->index > stack->next->next->index)
		ra(&stack, 1);
	else if (stack->next->index > stack->index 
		&& stack->next->index > stack->next->next->index)
		rra(&stack, 1);
	if (stack->index > stack->next->index)
		sa(&stack, 1);
}

static void	sort(t_node **stack_a, t_node **stack_b, int len)
{
	if (!is_sorted(*stack_a))
	{
		if (len == 2)
			sa(stack_a, 1);
		else if (len == 3)
			sort_three(*stack_a);
		else
			sort_stacks(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		exit (0);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		stack_init(&stack_a, argv);
		free_argv(argv);
	}
	else
		stack_init(&stack_a, argv + 1);
	assign_index(stack_a);
	sort(&stack_a, &stack_b, stack_len(stack_a));
	free_stack(&stack_a);
	free_stack(&stack_b); //Check this free
	return (0);
}
