/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rrarrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:59:11 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/17 11:35:55 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index00_rrarrb(t_swp_list **a, t_swp_list **to_push, t_swp_list **b)
{
	if ((*to_push)->index == 0 && (*to_push)->target->index == 0)
	{
		pb(a, b);
		return (1);
	}
	return (0);
}

int	index01_rrarrb(t_swp_list **a, t_swp_list **to_push, t_swp_list **b)
{
	int			i;
	int			rev_indexb;
	t_swp_list	*tail_b;

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

int	index10_rrarrb(t_swp_list **a, t_swp_list **to_push, t_swp_list **b)
{
	int			i;
	int			rev_indexa;
	t_swp_list	*tail_a;

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

int	index11_rrarrb(t_swp_list **a, t_swp_list **to_push, t_swp_list **b)
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

int	exec_rrarrb(t_swp_list **a, t_swp_list **to_push, t_swp_list **b)
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
