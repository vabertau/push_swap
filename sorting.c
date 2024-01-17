/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:04:35 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/17 11:37:30 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort2(t_swp_list **a)
{
	if ((*a)->nbr > (*a)->next->nbr)
	{
		sab(a, 1);
	}
	return (0);
}

int	sort3(t_swp_list **a)
{
	if (((*a)->nbr > (*a)->next->nbr)
		&& ((*a)->nbr > (*a)->next->next->nbr))
	{
		rab(a, 1);
	}
	else if (((*a)->next->nbr > (*a)->nbr)
		&& ((*a)->next->nbr > (*a)->next->next->nbr))
	{
		rrab(a, 1);
	}
	if ((*a)->nbr > (*a)->next->nbr)
	{
		sab(a, 1);
	}
	return (0);
}

int	stack_sorted(t_swp_list *a)
{
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
			return (0);
		else
			a = a->next;
	}
	return (1);
}

int	sortbig(t_swp_list **a, t_swp_list **b)
{
	int	hm_is;

	hm_is = howmany_instack(*a);
	if (hm_is == 4)
		pb(a, b);
	if (hm_is > 4)
	{
		pb(a, b);
		pb(a, b);
	}
	while (hm_is > 3 && !(stack_sorted(*a)))
	{
		init_nodes(a, b);
	}
	return (0);
}

int	sortall(t_swp_list **a, t_swp_list **b)
{
	int	hm_is;

	hm_is = howmany_instack(*a);
	if (hm_is == 2)
	{
		sort2(a);
		return (0);
	}
	if (hm_is == 3)
	{
		sort3(a);
		return (0);
	}
	if (hm_is > 3 && !stack_sorted(*a))
	{
		sortbig(a, b);
		return (0);
	}
	return (0);
}
