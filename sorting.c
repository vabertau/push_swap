/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:04:35 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/15 19:31:56 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	howmany_instack(swp_list *a)
{
	int	count;

	count = 0;
	while (a)
	{
		count++;
		a = a->next;
	}
	return (count);
}			

int	sort2(swp_list **a)
{
	if ((*a)->nbr > (*a)->next->nbr)
	{
		sab(a, 1);
	}
	return (0);
}

int	sort3(swp_list **a)
{
	//if (!((a->next->next->nbr >= a->next->nbr) && (a->next->next->nbr >= a->nbr)))
	if (((*a)->nbr > (*a)->next->nbr) && ((*a)->nbr > (*a)->next->next->nbr))
	{
		rab(a, 1);
	}
	else if (((*a)->next->nbr > (*a)->nbr) && ((*a)->next->nbr > (*a)->next->next->nbr))
	{
		rrab(a, 1);
	}
	if ((*a)->nbr > (*a)->next->nbr)
	{
		sab(a, 1);
	}
	return (0);
}

int	stack_sorted(swp_list *a)
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

int	sortbig(swp_list **a, swp_list **b)
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

int	sortall(swp_list **a, swp_list **b)
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
