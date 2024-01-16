/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rrarrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:59:11 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/16 19:03:04 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index00_rrarrb(swp_list **a, swp_list **to_push, swp_list **b)
{
	if ((*to_push)->index == 0 && (*to_push)->target->index == 0)
	{
		pb(a, b);
		return (1);
	}
	return (0);
}

int	index01_rrarrb(swp_list **a, swp_list **to_push, swp_list **b)
{
	int			i;
	int			rev_indexb;
	swp_list	*tail_b;

	i = 0;
	tail_b = *b;
	while (tail_b->next)
		tail_b = tail_b->next;
	rev_indexb = tail_b->index - (*to_push)->target->index;
	if ((*to_push)->index == 0)
	{
		while (i < rev_indexb + 1)
		{
			rrab(b, 2);
			i++;
		}
		pb(a, b);
		return (1);
	}
	return (0);
}

int	index10_rrarrb(swp_list **a, swp_list **to_push, swp_list **b)
{
	int			i;
	int			rev_indexa;
	swp_list	*tail_a;

	i = 0;
	tail_a = *a;
	while (tail_a->next)
		tail_a = tail_a->next;
	rev_indexa = tail_a->index - (*to_push)->index;
	if ((*to_push)->target->index == 0)
	{
		while (i < rev_indexa + 1)
		{
			rrab(a, 1);
			i++;
		}
		pb(a, b);
		return (1);
	}
	return (0);
}

int	index11_rrarrb(swp_list **a, swp_list **to_push, swp_list **b)
{
	int	i;
	int	rev_indexa;
	int	rev_indexb;

	i = 0;
	rev_indexa = get_revindex(a, to_push);
	rev_indexb = get_revindex(b, &((*to_push)->target));
	if (pc_rrarrb(*a, *to_push, *b) == rev_indexa + 1)
	{
		while (i++ < rev_indexb + 1)
			rrr(a, b);
		i--;
		while (i++ < rev_indexa + 1)
			rrab(a, 1);
		return (pb(a, b), 0);
	}
	while (i++ < rev_indexa + 1)
		rrr(a, b);
	i--;
	while (i++ < rev_indexb + 1)
		rrab(b, 2);
	pb(a, b);
	return (1);
}

int	exec_rrarrb(swp_list **a, swp_list **to_push, swp_list **b)
{
	int	i;
	int	rev_indexa;
	int	rev_indexb;

	i = 0;
	rev_indexa = get_revindex(a, to_push);
	rev_indexb = get_revindex(b, &((*to_push)->target));
	if (index00_rrarrb(a, to_push, b))
		return (0);
	if (index01_rrarrb(a, to_push, b))
		return (0);
	if (index10_rrarrb(a, to_push, b))
		return (0);
	index11_rrarrb(a, to_push, b);
	return (0);
}
