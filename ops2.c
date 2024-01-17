/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:20:06 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/17 11:36:49 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ss(t_swp_list **a, t_swp_list **b)
{
	sab(a, 0);
	sab(b, 0);
	write(1, "ss\n", 3);
	return (0);
}

int	pb(t_swp_list **a, t_swp_list **b)
{
	t_swp_list	*tmp;
	t_swp_list	*tmp2;

	if (!(*b))
	{
		tmp = *a;
		*a = (*a)->next;
		*b = tmp;
		(*b)->next = NULL;
	}
	else
	{
		tmp = *a;
		*a = (*a)->next;
		tmp2 = *b;
		*b = tmp;
		(*b)->next = tmp2;
	}
	write(1, "pb\n", 3);
	return (0);
}

int	pa(t_swp_list **a, t_swp_list **b)
{
	t_swp_list	*tmp;
	t_swp_list	*tmp2;

	if (!(*a))
	{
		tmp = *b;
		*b = (*b)->next;
		*a = tmp;
		(*a)->next = NULL;
	}
	else
	{
		tmp = *b;
		*b = (*b)->next;
		tmp2 = *a;
		*a = tmp;
		(*a)->next = tmp2;
	}
	write(1, "pa\n", 3);
	return (0);
}
