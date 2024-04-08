/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:51:32 by ffleitas          #+#    #+#             */
/*   Updated: 2024/04/08 16:21:12 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || argc == 2 && !argv[0][1])
		return (NULL);
	
	return (0);
}
/* int main(int argc, char **argv)
{
	t_node *a;
	t_node *b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (argc == 2)
		argv = split(argv[1], ' ');
	ft_printf("%s\n", argv[0]);
	ft_printf("%s\n", argv[1]);
	ft_printf("%s\n", argv[2]);
	return (0);
} */

