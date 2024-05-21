/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:57:36 by ffleitas          #+#    #+#             */
/*   Updated: 2024/05/21 20:21:42 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct node
{
	int 	val;
	int 	index;
	int 	price;
	bool	above_midpoint;
	bool	cheapest;
	struct node *target;
	struct node *next;
	struct node *prev;
}				t_node;

//Stack initialization
void		stack_init(t_node **stack_a, char **argv);

//Push_swap utils
long int	ft_atol(const char *str);

//Error handling
int			syntax_error(char *argv);
void		free_stack(t_node **stack);
void		free_error(t_node **stack_a);
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

//Sort functions
void	sort(t_node **stack_a, t_node **stack_b, int len);
bool    stack_sorted(t_node *stack);
void    sort_three(t_node **stack);
void    sort_five(t_node **stack_a, t_node **stack_b);
void	big_sort(t_node **stack_a, t_node **stack_b);
void 	move_nodes(t_node **stack_a, t_node **stack_b);

//Sort utils
int    stack_len(t_node *stack);
t_node  *find_highest(t_node *stack);
t_node  *find_lowest(t_node *stack);
t_node *find_cheapest(t_node *stack);
void   stack_index(t_node *stack);


#endif