/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:57:36 by ffleitas          #+#    #+#             */
/*   Updated: 2024/04/11 20:41:40 by ffleitas         ###   ########.fr       */
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

//Operations Utils
t_node	*find_last(t_node *head);

//Push
void	pa(t_node **stack_a, t_node **stack_b, int print);
void	pb(t_node **stack_a, t_node **stack_b, int print);

//Swap
void	sa(t_node **stack_a, int print);
void	sb(t_node **stack_b, int print);
void	ss(t_node **stack_a, t_node **stack_b, int print);

//Rotate
void	ra(t_node **stack_a, int print);
void	rb(t_node **stack_b, int print);
void	rr(t_node **stack_a, t_node **stack_b, int print);

//Reverse Rotate
void	rra(t_node **stack_a, int print);
void	rrb(t_node **stack_b, int print);
void	rrr(t_node **stack_a, t_node **stack_b, int print);


#endif