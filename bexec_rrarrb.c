/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bexec_rrarrb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:21:26 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/16 18:26:53 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

