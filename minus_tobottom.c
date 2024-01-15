/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_tobottom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:28:07 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/15 20:02:36 by vabertau         ###   ########.fr       */
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

	init_nodes(a, a);
	lowest = find_lowest(*a);
	//printf("lowest = %li", lowest->nbr);
	i = 0;
	tail_a = *a;
	while (tail_a->next)
		tail_a = tail_a->next;
	index_lowest = find_index(*a, lowest);
	rev_indexlowest = find_index(*a, tail_a) - lowest->index;
	//printf("index_lowest = %i, rev_indexlowest = %i, tail_a = %li", index_lowest, rev_indexlowest, tail_a->nbr);
	if (above_median(*a, index_lowest) == 0)
	{
		while (i < index_lowest)
		{
			rab(a, 1);
			i++;
		}
	}
	else
	{
		while (i < rev_indexlowest + 1)
		{
			rrab(a, 1);
			i++;
		}
	}
	return (0);
}
