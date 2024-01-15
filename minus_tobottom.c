/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_tobottom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:28:07 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/15 17:50:52 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	minus_tobottom(swp_list **a)
{
	swp_list	*lowest;
	swp_list        *tail_a;
	int		i;
	int		index_lowest;
	int		rev_indexlowest;

	lowest = find_lowest(*a);
	i = 0;
	tail_a = *a;
	while (tail_a->next)
		tail_a = tail_a->next;
	index_lowest = find_index(*a, lowest);
	rev_indexlowest = find_index(*a, tail_a) - lowest->index;
	if (!above_median(lowest, index_lowest))
	{
		while (i < index_lowest)
		{
			rab(a, 1);
			i++;
		}
	}
	else
	{
		while (i < rev_indexlowest)
		{
			rrab(a, 1);
			i++;
		}
	}
	return (0);
}
