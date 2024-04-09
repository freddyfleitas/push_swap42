/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:57:36 by ffleitas          #+#    #+#             */
/*   Updated: 2024/04/09 20:00:32 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct node
{
	long int val;
	struct node *next;
	struct node *prev;
}				t_node;

//Stack initialization
void		stack_init(t_node **stack_a, char **argv);

//Push_swap utils
long int	ft_atol(const char *str);

//Error handling
int			syntax_error(char *argv);
void		free_and_exit(t_node **stack_a);
int			repeated_numbers(t_node *stack_a, int number);

#endif