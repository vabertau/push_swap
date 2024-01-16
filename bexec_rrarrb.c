/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bexec_rrarrb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:21:26 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/16 18:40:54 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     bindex00_rrarrb(swp_list **a, swp_list **to_push, swp_list **b)
{
        if ((*to_push)->index == 0 && (*to_push)->target->index == 0)
        {
                pa(a, b);
                return (1);
        }
        return (0);
}

int     bindex01_rrarrb(swp_list **a, swp_list **to_push, swp_list **b)
{
	int	i;
        int             rev_indexa;

        i = 0;
        rev_indexa = get_revindex(a, &((*to_push)->target));
        if ((*to_push)->index == 0)
        {
                while (i < rev_indexa + 1)
                {
                        rrab(a, 1);
                        i++;
                }
                pa(a, b);
                return (1);
        }
	return (0);
}

int     bindex10_rrarrb(swp_list **a, swp_list **to_push, swp_list **b)
{
	int	i;
        int             rev_indexb;

        rev_indexb = get_revindex(b, to_push);
	i = 0;
        if ((*to_push)->target->index == 0)
        {
                while (i < rev_indexb + 1)
                {
                        rrab(b, 2);
                        i++;
                }
                pa(a, b);
                return (1);
        }
	return(0);
}

int     bindex11_rrarrb(swp_list **a, swp_list **to_push, swp_list **b)
{
        int     i;
        int             rev_indexa;
        int             rev_indexb;

        i = 0;
        rev_indexa = get_revindex(a, &((*to_push)->target));
        rev_indexb = get_revindex(b, to_push);
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
        return (1);
}

int     bexec_rrarrb(swp_list **a, swp_list **to_push, swp_list **b)
{
        int     i;
        int             rev_indexa;
        int             rev_indexb;

        i = 0;
        rev_indexa = get_revindex(a, &((*to_push)->target));
        rev_indexb = get_revindex(b, to_push);
        /*if ((*to_push)->index == 0 && (*to_push)->target->index == 0)
        {
                pa(a, b);
                return (0);
        }*/
        if (bindex00_rrarrb(a, to_push, b))
                return (0);
        if (bindex01_rrarrb(a, to_push, b))
                return (0);
        /*if ((*to_push)->index == 0)
        {
                while (i < rev_indexa + 1)
                {
                        rrab(a, 1);
                        i++;
                }
                pa(a, b);
                return (0);
        }*/
        /*if ((*to_push)->target->index == 0)
        {
                while (i < rev_indexb + 1)
                {
                        rrab(b, 2);
                        i++;
                }
                pa(a, b);
                return (0);
        }*/
        if (bindex10_rrarrb(a, to_push, b))
                return (0);
        /*if (bpc_rrarrb(*a, *to_push, *b) == rev_indexa + 1)
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
        pa(a, b);*/
	bindex11_rrarrb(a, to_push, b);
        return (0);
}

