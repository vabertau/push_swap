/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binit_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:13:08 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/16 14:50:22 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

swp_list	*find_lowest(swp_list *a)
{
	swp_list	*ret;

	ret = a;
	while (a)
	{
		if (a->nbr < ret->nbr)
			ret = a;
		a = a->next;
	}
	return (ret);
}

int	bfind_target(swp_list *a, swp_list *b)
{
	swp_list	*tmp;

	tmp = a;
	while (b)
	{
		b->target = NULL;
		a = tmp;
		while (a)
		{
			if (a->nbr > b->nbr)
			{
				if (b->target == NULL)
					b->target = a;
				else if (a->nbr < b->target->nbr)
					b->target = a;
			}
			a = a->next;
		}
		if (b->target == NULL)
			b->target = find_lowest(tmp);
		b = b->next;
	}
	return (0);
}

int	bpush_cost(swp_list *a, swp_list *b)
{
	swp_list	*to_push;

	to_push = b;
	while (to_push)
	{
		to_push->push_cost = bpc_rarb(a, to_push, b);
		to_push->op = 1;
		if (bpc_rrarrb(a, to_push, b) < to_push->push_cost)
		{
			to_push->push_cost = bpc_rrarrb(a, to_push, b);
			to_push->op = 2;
		}
		if (bpc_rarrb(a, to_push, b) < to_push->push_cost)
		{
			to_push->push_cost = bpc_rarrb(a, to_push, b);
			to_push->op = 3;
		}
		if (bpc_rrarb(a, to_push, b) < to_push->push_cost)
		{
			to_push->push_cost = bpc_rrarb(a, to_push, b);
			to_push->op = 4;
		}
		to_push = to_push->next;
	}
	return (0);
}

int	binit_nodes(swp_list **a, swp_list **b)
{
	bfind_target(*a, *b);
	set_allindex(*a, *b);
	bpush_cost(*a, *b);
	set_cheapest(*b, *a);
	return (0);
}
