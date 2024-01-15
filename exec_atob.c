/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_atob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:14:48 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/15 16:51:06 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_rarb(swp_list **to_push, swp_list **b)
{
	int	i;

	i = 0;
	if ((*to_push)->index <= (*to_push)->target->index)
	{
		while (i < (*to_push)->index)
		{
			rr(to_push, b);
			i++;
		}
		while (i < (*to_push)->target->index)
		{
			rab(b, 2);
			i++;
		}
		pb(to_push, b);
	}
	else
	{
		while (i < (*to_push)->target->index)
                {
                        rr(to_push, b);
                        i++;
                }
                while (i < (*to_push)->index)
                {
                        rab(to_push, 1);
                        i++;
                }
		pb(to_push, b);
	}
	return (0);
}

int     exec_rrarrb(swp_list **a, swp_list **to_push, swp_list **b)
{
	int	i;
        swp_list        *tail_a;
        swp_list        *tail_b;
        int             rev_indexa;
        int             rev_indexb;

        tail_a = *a;
        tail_b = *b;
	i = 0;
        while (tail_a->next)
                tail_a = tail_a->next;
        while (tail_b->next)
                tail_b = tail_b->next;
        rev_indexa = tail_a->index - (*to_push)->index;
        rev_indexb = tail_b->index - (*to_push)->target->index;
	if ((*to_push)->index == 0 && (*to_push)->target->index == 0)
	{
		pb(a, b);
		return (0);
	}
	if ((*to_push)->index == 0)
	{
		while (i < rev_indexb + 1)
		{
			rrab(b, 2);
			i++;
		}
		pb(a, b);
		return (0);
	}
	if ((*to_push)->target->index == 0)
	{
                while (i < rev_indexa + 1)
                {
                        rrab(a, 1); 
                        i++;
                }
		pb(a, b);
		return (0);
	}
	if (pc_rrarrb(*a, *to_push, *b) == rev_indexa + 1)
	{
		while (i < rev_indexb + 1)
		{
			rrr(a, b);
			i++;
		}
		while (i < rev_indexa + 1)
		{
			rrab(a, 1);
			i++;
		}
	}
	else
	{
                while (i < rev_indexa + 1)
                {
                        rrr(a, b);
                        i++;
                }
                while (i < rev_indexb + 1)
                {
                        rrab(b, 2);
                        i++;
                }
	}
	pb(a, b);
        return (0);
}

int     exec_rarrb(swp_list **a, swp_list **to_push, swp_list **b)
{
        swp_list        *tail_b;
        int             rev_indexb;
	int		i;

        tail_b = *b;
        i = 0;
        while (tail_b->next)
                tail_b = tail_b->next;
        rev_indexb = tail_b->index - (*to_push)->target->index;	
        if ((*to_push)->target->index == 0)
	{
                while (i < (*to_push)->index)
                {
			rab(to_push, 1);
                        i++;
                }
	}
        else
	{
		while (i < (*to_push)->index)
		{
			rab(to_push, 1);
			i++;
		}
		i = 0;
                while (i < rev_indexb + 1)
                {
                        rrab(b, 2);
                        i++;
                }
	}
	pb(a, b);
	return (0);
}

int     exec_rrarb(swp_list **a, swp_list **to_push, swp_list **b)
{
        swp_list        *tail_a;
        int             rev_indexa;
        int             i;

        tail_a = *a;
        i = 0;
        while (tail_a->next)
                tail_a = tail_a->next;
        rev_indexa = tail_a->index - (*to_push)->index;
        if ((*to_push)->index == 0)
        {
                while (i < (*to_push)->target->index)
                {
                        rab(b, 2);
                        i++;
                }
        }
        else
        {
                while (i < (*to_push)->target->index)
                {
                        rab(b, 2);
                        i++;
                }
                i = 0;
                while (i < rev_indexa + 1)
                {
                        rrab(to_push, 1);
                        i++;
                }
        }
        pb(a, b);
	return (0);
}

#include <stdio.h>

int	exec_1atob(swp_list **a, swp_list **b)
{
	swp_list	**to_push;

	to_push = a;
	while (*to_push)
	{
		init_nodes(to_push, b);
		if ((*to_push)->is_cheapest == 1)
		{
			printf("EXEC\nnumber = %li:\ntarget node = %li\nindexa = %i\nindexb = %i\npush_cost = %i\nis_cheapest = %i\nop = %i\n\n",
					(*to_push)->nbr, (*to_push)->target->nbr, (*to_push)->index,
					(*to_push)->target->index, (*to_push)->push_cost,
					(*to_push)->is_cheapest, (*to_push)->op);
			if ((*to_push)->op == 1)
				exec_rarb(to_push, b);
			else if ((*to_push)->op == 2)
				exec_rrarrb(a, to_push, b);
			else if ((*to_push)->op == 3)
				exec_rarrb(a, to_push, b);
			else if ((*to_push)->op == 4)
				exec_rrarb(a, to_push, b);
			return (0);
		}
		*to_push = (*to_push)->next;
	}
	return (0);
}

int	exec_allatob(swp_list **a, swp_list **b)
{
        if (howmany_instack(*a) > 3)
                pb(a, b);
        if (howmany_instack(*a) > 3)
                pb(a, b);
	while (howmany_instack(*a) > 3)
		exec_1atob(a, b);
	return (0);
}

#include <stdio.h>

int     main(int argc, char **argv)
{
        swp_list        **a;
        swp_list        **b;
        swp_list        *tmp;

        a = malloc(sizeof(swp_list *));
        b = malloc(sizeof(swp_list *));
        *a = NULL;
        *b = NULL;

        cr_stacks(a, b, argc, argv);
        printf("%i args\n", argc); // to suppress
        tmp = *a;
        //pb(a, b);
        //pb(a, b);		
	//init_nodes(a, b);
        //exec_rrarrb(a, a, b);
	//exec_rarrb(a, &((*a)->next->next), b);
	//exec_rarrb(a, a, b);
        //exec_rrarb(a, a, b);
	//exec_rrarb(a, &((*a)->next->next), b);
	exec_allatob(a, b);
	exec_allbtoa(a, b);
	printf("\n====PROGRAM ENDED====\n");
        while (*a)
        {
                printf("number = %li:\ntarget node = %li\nindexa = %i\nindexb = %i\npush_cost = %i\nis_cheapest = %i\n\n", (*a)->nbr, (*a)->target->nbr, (*a)->index, (*a)->target->index, (*a)->push_cost, (*a)->is_cheapest);//testing target nodes
                *a = (*a)->next;
        }
        while (*b)
        {
                printf("number b = %li\n", (*b)->nbr);
                *b = (*b)->next;
        }
        return (0);
}
