/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_btoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:53:13 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/17 11:35:45 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bexec_rarb(t_swp_list **b, t_swp_list **to_push, t_swp_list **a)
{
	int	i;

	i = 0;
	if ((*to_push)->index <= (*to_push)->target->index)
	{
		while (i++ < (*to_push)->index)
			rr(b, a);
		i--;
		while (i++ < (*to_push)->target->index)
			rab(a, 1);
		pa(a, b);
	}
	else
	{
		while (i++ < (*to_push)->target->index)
			rr(b, a);
		i--;
		while (i++ < (*to_push)->index)
			rab(b, 2);
		i--;
		pa(a, b);
	}
	return (0);
}

int	bexec_rarrb(t_swp_list **a, t_swp_list **to_push, t_swp_list **b)
{
	t_swp_list	*tail_b;
	int			rev_indexb;
	int			i;

	tail_b = *b;
	i = 0;
	while (tail_b->next)
		tail_b = tail_b->next;
	rev_indexb = tail_b->index - (*to_push)->index;
	if ((*to_push)->index == 0)
	{
		while (i++ < (*to_push)->target->index)
			rab(a, 1);
		i--;
	}
	else
	{
		while (i++ < (*to_push)->target->index)
			rab(a, 1);
		i = 0;
		while (i++ < rev_indexb + 1)
			rrab(b, 2);
	}
	pa(a, b);
	return (0);
}

int	bexec_rrarb(t_swp_list **a, t_swp_list **to_push, t_swp_list **b)
{
	t_swp_list	*tail_a;
	int			rev_indexa;
	int			i;

	tail_a = *a;
	i = 0;
	while (tail_a->next)
		tail_a = tail_a->next;
	rev_indexa = tail_a->index - (*to_push)->target->index;
	if ((*to_push)->target->index == 0)
	{
		while (i++ < (*to_push)->index)
			rab(b, 2);
		i--;
	}
	else
	{
		while (i++ < (*to_push)->index)
			rab(b, 2);
		i = 0;
		while (i++ < rev_indexa + 1)
			rrab(a, 1);
	}
	pa(a, b);
	return (0);
}

int	exec_1btoa(t_swp_list **a, t_swp_list **b)
{
	t_swp_list	*to_push;

	to_push = *b;
	binit_nodes(a, b);
	while (to_push)
	{
		if (to_push->is_cheapest == 1)
		{
			if (to_push->op == 1)
				bexec_rarb(b, &to_push, a);
			else if (to_push->op == 2)
				bexec_rrarrb(a, &to_push, b);
			else if (to_push->op == 3)
				bexec_rarrb(a, &to_push, b);
			else if (to_push->op == 4)
				bexec_rrarb(a, &to_push, b);
			return (0);
		}
		to_push = to_push->next;
	}
	return (0);
}

int	exec_allbtoa(t_swp_list **a, t_swp_list **b)
{
	while (howmany_instack(*b))
		exec_1btoa(a, b);
	return (0);
}
