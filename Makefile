# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 16:03:03 by ffleitas          #+#    #+#              #
#    Updated: 2024/06/01 20:25:28 by ffleitas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libftprintf.a

SRC = push_swap.c stack_init.c error_handler.c movements/rotate.c \
		movements/swap.c movements/push.c movements/rev_rotate.c \
		alternative_sort.c alternative_sort_utils.c

OBJS = $(SRC:.c=.o)

CC = gcc -g3 -Wall -Wextra #-Werror #-fsanitize=address

all: $(NAME) 

$(LIBFT):
	@$(MAKE) -s -C libft

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) $(LIBFT) -o $@

clean:
	@$(MAKE) -s -C libft clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -s -C libft fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re