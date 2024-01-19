# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 14:58:14 by vabertau          #+#    #+#              #
#    Updated: 2024/01/17 16:56:46 by vabertau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

CC= cc $(FLAGS)

FLAGS=-Wall -Werror -Wextra

SRCS=sorting.c push_swap.c lst.c ops.c init_nodes.c cost_ops.c exec_atob.c exec_btoa.c binit_nodes.c bcost_ops.c minus_tobottom.c parsing.c exec_atobmain.c exec_rrarrb.c main.c bexec_rrarrb.c utils.c ops2.c utils2.c


OBJS=$(SRCS:.c=.o)

LIBFT = libft/libft.a

$(NAME): $(LIBFT) $(OBJS)
	cc $(FLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

$(LIBFT):
	make -C libft all

clean:
	make -C libft/ clean
	rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

all: $(NAME)
