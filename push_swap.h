/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:57:36 by ffleitas          #+#    #+#             */
/*   Updated: 2024/06/02 21:54:49 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct node
{
	int			val;
	int			index;
	int			current_index;
	int			target_index;
	int			cost_a;
	int			cost_b;
	bool		assigned;
	struct node	*next;
	struct node	*prev;
}				t_node;

/* typedef struct node
{
	int			val;
	int			index;
	int			price;
	bool		above_midpoint;
	bool		cheapest;
	bool		assigned;
	struct node	*target;
	struct node	*next;
	struct node	*prev;
}				t_node; */

//Error handling
int			syntax_error(char *argv);
void		free_stack(t_node **stack);
void		free_argv(char **argv);
void		free_error(t_node **stack_a);
int			repeated_numbers(t_node *stack_a, int number);

//Movements
void		pa(t_node **stack_a, t_node **stack_b, int print);
void		pb(t_node **stack_a, t_node **stack_b, int print);
void		sa(t_node **stack_a, int print);
void		sb(t_node **stack_b, int print);
void		ss(t_node **stack_a, t_node **stack_b, int print);
void		ra(t_node **stack_a, int print);
void		rb(t_node **stack_b, int print);
void		rr(t_node **stack_a, t_node **stack_b, int print);
void		rra(t_node **stack_a, int print);
void		rrb(t_node **stack_b, int print);
void		rrr(t_node **stack_a, t_node **stack_b, int print);

//Sort functions
/* void		sort(t_node **stack_a, t_node **stack_b, int len);
bool		stack_sorted(t_node *stack);
void		sort_three(t_node **stack);
void		sort_five(t_node **stack_a, t_node **stack_b);
void		big_sort(t_node **stack_a, t_node **stack_b);
void		move_nodes(t_node **stack_a, t_node **stack_b); */

//Alternative Sort
void		sort_three(t_node *stack);
void		assign_index(t_node *stack);
void		current_index(t_node *stack);
void        sort_stacks(t_node **stack_a, t_node **stack_b);
int			stack_len(t_node *stack);
bool		is_sorted(t_node *stack);

//Push Swap Utils
void		stack_init(t_node **stack_a, char **argv);
long int	ft_atol(const char *str);
t_node		*find_last(t_node *head);
/*int			stack_len(t_node *stack);
t_node		*find_highest(t_node *stack);
t_node		*find_lowest(t_node *stack);
t_node		*find_cheapest(t_node *stack);
void		stack_index(t_node *stack); */

#endif