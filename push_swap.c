/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:51:32 by ffleitas          #+#    #+#             */
/*   Updated: 2024/04/19 17:28:56 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
	{
		ft_printf("Error\n");
		return (0);
	}
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		stack_init(&stack_a, argv);
	}
	else
		stack_init(&stack_a, argv + 1);
	if (!stack_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a, 1);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		/*else
			sort_stacks(&stack_a, &stack_b);*/
	}
	else
		printf("Stack is already sorted ;)\n");
	free_stack(&stack_a);
	return (0);
}
