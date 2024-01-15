/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_atob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:14:48 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/15 22:21:29 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_rarb(swp_list **a, swp_list **to_push, swp_list **b)
{
	int	i;

	i = 0;
	if ((*to_push)->index <= (*to_push)->target->index)
	{
		while (i < (*to_push)->index)
		{
			rr(a, b);
			i++;
		}
		while (i < (*to_push)->target->index)
		{
			rab(b, 2);
			i++;
		}
		pb(a, b);
		return (0); //useless
	}
	else
	{
		while (i < (*to_push)->target->index)
                {
                        rr(a, b);
                        i++;
                }
                while (i < (*to_push)->index)
                {
                        rab(a, 1);
                        i++;
                }
		pb(a, b);
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
	else if ((*to_push)->index == 0)
	{
		while (i < rev_indexb + 1)
		{
			rrab(b, 2);
			i++;
		}
		pb(a, b);
		return (0);
	}
	else if ((*to_push)->target->index == 0)
	{
                while (i < rev_indexa + 1)
                {
                        rrab(a, 1); 
                        i++;
                }
		pb(a, b);
		return (0);
	}
	else if (pc_rrarrb(*a, *to_push, *b) == rev_indexa + 1)
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
			rab(a, 1);
                        i++;
                }
	}
        else
	{
		while (i < (*to_push)->index)
		{
			rab(a, 1);
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
                        rrab(a, 1);
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
	swp_list	*tmp; //to rm
	to_push = a;
	init_nodes(a,b);
	while (*to_push)
	{
		//init_nodes(a, b);
        	tmp = *a;//to rm
        	while (tmp)//to rm
        	{
                	printf("number XXX = %li:\nindexa = %i\n\n", (tmp)->nbr, (tmp)->index);//testing target nodes
                	tmp = (tmp)->next;
        	}
		if ((*to_push)->is_cheapest == 1)
		{
                        printf("EXEC\nnumber = %li:\ntarget node = %li\nindexa = %i\nindexb = %i\npush_cost = %i\nis_cheapest = %i\nop = %i\n\n",
                                        (*to_push)->nbr, (*to_push)->target->nbr, (*to_push)->index,
                                        (*to_push)->target->index, (*to_push)->push_cost,
                                        (*to_push)->is_cheapest, (*to_push)->op);
			if ((*to_push)->op == 1)
				exec_rarb(a, to_push, b);
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
	{
		printf("\nhm_is = %i\n", howmany_instack(*a));
		exec_1atob(a, b);
	}
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
	exec_allatob(a, b);
        tmp = *a;
        while (tmp)
        {
                printf("number bf s3 = %li:\nindexa = %i\n\n", (tmp)->nbr, (tmp)->index);//testing target nodes
                tmp = (tmp)->next;
        }
	//sort3(a);
	exec_allbtoa(a, b);
	minus_tobottom(a);	
	printf("\n====PROGRAM ENDED====\n");
        while (*a)
        {
                printf("number = %li:\nindexa = %i\n\n", (*a)->nbr, (*a)->index);//testing target nodes
                *a = (*a)->next;
        }	
        while (*b)
        {
                printf("number b = %li\n", (*b)->nbr);
                *b = (*b)->next;
        }
        return (0);
/*
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
        return (0);*/
}
