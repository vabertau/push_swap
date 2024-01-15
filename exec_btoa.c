/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_btoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:53:13 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/15 18:20:39 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     bexec_rarb(swp_list **to_push, swp_list **a)
{
        int     i;

        i = 0;
        if ((*to_push)->index <= (*to_push)->target->index)
        {
                while (i < (*to_push)->index)
                {
                        rr(to_push, a);
                        i++;
                }
                while (i < (*to_push)->target->index)
                {
                        rab(a, 1);
                        i++;
                }
                pa(a, to_push);
        }
        else
        {
                while (i < (*to_push)->target->index)
                {
                        rr(to_push, a);
                        i++;
                }
                while (i < (*to_push)->index)
                {
                        rab(to_push, 2);
                        i++;
                }
                pa(a, to_push);
        }
        return (0);
}

int     bexec_rrarrb(swp_list **a, swp_list **to_push, swp_list **b)
{
        int     i;
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
        rev_indexa = tail_a->index - (*to_push)->target->index;
        rev_indexb = tail_b->index - (*to_push)->index;
        if ((*to_push)->index == 0 && (*to_push)->target->index == 0)
        {
                pa(a, b);
                return (0);
        }
        if ((*to_push)->index == 0)
        {
                while (i < rev_indexa + 1)
                {
                        rrab(a, 1);
                        i++;
                }
                pa(a, b);
                return (0);
        }
        if ((*to_push)->target->index == 0)
        {
                while (i < rev_indexb + 1)
                {
                        rrab(b, 2);
                        i++;
                }
                pa(a, b);
                return (0);
        }
        if (bpc_rrarrb(*a, *to_push, *b) == rev_indexa + 1)
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
        pa(a, b);
        return (0);
}

int     bexec_rarrb(swp_list **a, swp_list **to_push, swp_list **b)
{
        swp_list        *tail_b;
        int             rev_indexb;
        int             i;

        tail_b = *b;
        i = 0;
        while (tail_b->next)
                tail_b = tail_b->next;
        rev_indexb = tail_b->index - (*to_push)->index;
        if ((*to_push)->index == 0)
        {
                while (i < (*to_push)->target->index)
                {
                        rab(a, 1);
                        i++;
                }
        }
        else
        {
                while (i < (*to_push)->target->index)
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
        pa(a, b);
	return (0);
}

int     bexec_rrarb(swp_list **a, swp_list **to_push, swp_list **b)
{
        swp_list        *tail_a;
        int             rev_indexa;
        int             i;

        tail_a = *a;
        i = 0;
        while (tail_a->next)
                tail_a = tail_a->next;
        rev_indexa = tail_a->index - (*to_push)->target->index;
        if ((*to_push)->target->index == 0)
        {
                while (i < (*to_push)->index)
                {
                        rab(b, 2);
                        i++;
                }
        }
        else
        {
                while (i < (*to_push)->index)
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
        pa(a, b);
	return (0);
}

#include <stdio.h>

int     exec_1btoa(swp_list **a, swp_list **b)
{
        swp_list        **to_push;

        to_push = b;
        while (*to_push)
        {
                binit_nodes(a, to_push);
                if ((*to_push)->is_cheapest == 1)
                {
                        if ((*to_push)->op == 1)
                                bexec_rarb(to_push, a);
                        else if ((*to_push)->op == 2)
                                bexec_rrarrb(a, to_push, b);
                        else if ((*to_push)->op == 3)
                                bexec_rarrb(a, to_push, b);
                        else if ((*to_push)->op == 4)
                                bexec_rrarb(a, to_push, b);
                        return (0);
                }
                *to_push = (*to_push)->next;
        }
        return (0);
}


int     exec_allbtoa(swp_list **a, swp_list **b)
{
        while (howmany_instack(*b))
                exec_1btoa(a, b);
        return (0);
}

