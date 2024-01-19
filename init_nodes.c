/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:54:58 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/17 17:14:54 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target(t_swp_list *a, t_swp_list *b)
{
	t_swp_list	*tmp;

	tmp = b;
	while (a)
	{
		a->target = NULL;
		b = tmp;
		while (b)
		{
			if (b->nbr < a->nbr)
			{
				if (a->target == NULL)
					a->target = b;
				else if (b->nbr > a->target->nbr)
					a->target = b;
			}
			b = b->next;
		}
		if (a->target == NULL)
			a->target = find_biggest(tmp);
		a = a->next;
	}
	return (0);
}

int	push_cost(t_swp_list *a, t_swp_list *b)
{
	t_swp_list	*to_push;

	to_push = a;
	while (to_push)
	{
		to_push->push_cost = pc_rarb(to_push);
		to_push->op = 1;
		if (pc_rrarrb(a, to_push, b) < to_push->push_cost)
		{
			to_push->push_cost = pc_rrarrb(a, to_push, b);
			to_push->op = 2;
		}
		if (pc_rarrb(to_push, b) < to_push->push_cost)
		{
			to_push->push_cost = pc_rarrb(to_push, b);
			to_push->op = 3;
		}
		if (pc_rrarb(a, to_push) < to_push->push_cost)
		{
			to_push->push_cost = pc_rrarb(a, to_push);
			to_push->op = 4;
		}
		to_push = to_push->next;
	}
	return (0);
}

int	set_allindex(t_swp_list *a, t_swp_list *b)
{
	t_swp_list	*head_a;
	t_swp_list	*head_b;

	head_a = a;
	head_b = b;
	while (a)
	{
		a->index = find_index(head_a, a);
		a = a->next;
	}
	while (b)
	{
		b->index = find_index(head_b, b);
		b = b->next;
	}
	return (0);
}

int	set_cheapest(t_swp_list *a)
{
	t_swp_list	*tmp;

	tmp = a;
	a->is_cheapest = 1;
	while (a->next)
	{
		if (a->next->push_cost < tmp->push_cost)
		{
			a->next->is_cheapest = 1;
			tmp->is_cheapest = 0;
			tmp = a->next;
		}
		a = a->next;
	}
	return (0);
}

int	init_nodes(t_swp_list **a, t_swp_list **b)
{
	find_target(*a, *b);
	set_allindex(*a, *b);
	push_cost(*a, *b);
	set_cheapest(*a);
	return (0);
}

/* ================== TEST INIT_NODES ================*/
/*
#include <stdio.h>

int     main(int argc, char **argv)
{
        t_swp_list        **a;
        t_swp_list        **b;
        t_swp_list        *tmp;

        a = malloc(sizeof(t_swp_list *));
        b = malloc(sizeof(t_swp_list *));
        *a = NULL;
        *b = NULL;

        cr_stacks(a, b, argc, argv);
        ft_lstadd_back(b, ft_lstnew(8));
//adding elements in stack b for test
        ft_lstadd_back(b, ft_lstnew(12));
	ft_lstadd_back(b, ft_lstnew(15));
	printf("%i args\n", argc); // to suppress
        tmp = *a;
	init_nodes(a, b);
	exec_atob(a, b);
	printf("init_nodes executed\n");    
	while (*a)
        {
                printf("number = %li:\ntarget node = %li\n
		indexa = %i\nindexb = %i\npush_cost = %i\n
		is_cheapest = %i\n\n", (*a)->nbr, (*a)->target->nbr,
		(*a)->index, (*a)->target->index, (*a)->push_cost,
		(*a)->is_cheapest);//testing target nodes
                *a = (*a)->next;
        }
        while (*b)
        {
                printf("number b = %li\n", (*b)->nbr);
                *b = (*b)->next;
        }	
        return (0);
}
*/
