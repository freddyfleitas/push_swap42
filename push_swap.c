/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:51:32 by ffleitas          #+#    #+#             */
/*   Updated: 2024/05/25 20:59:56 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_node **stack_a, t_node **stack_b, int len)
{
	if (len == 2)
		sa(stack_a, 1);
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 5)
		sort_five(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
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
	if (!stack_sorted(stack_a))
		sort(&stack_a, &stack_b, stack_len(stack_a));
	free_stack(&stack_a);
	return (0);
}
