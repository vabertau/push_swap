# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 14:58:14 by vabertau          #+#    #+#              #
#    Updated: 2024/01/16 11:37:30 by vabertau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ADD FLAGS REMOVE -g REMOVE TESTOPS

NAME=push_swap

CC= cc -g

TESTOPS=test_ops

FLAGS=-Wall -Werror -Wextra

SRCS=sorting.c push_swap.c lst.c ops.c init_nodes.c cost_ops.c exec_atob.c exec_btoa.c binit_nodes.c bcost_ops.c minus_tobottom.c parsing.c


OBJS=$(SRCS:.c=.o)

LIBFT = libft/libft.a

$(NAME): $(LIBFT) $(OBJS)
	cc -g $(OBJS) ./libft/libft.a -o $(NAME)

$(TESTOPS):
	cc -g ops.c lst.c push_swap.c sorting.c libft/ft_split.c libft/ft_substr.c libft/ft_strlen.c libft/ft_strdup.c -o test_ops

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
	
