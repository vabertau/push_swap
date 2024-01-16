/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bcost_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:40:06 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/16 14:45:13 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bpc_rarb(swp_list *a, swp_list *to_push, swp_list *b)
{
	int	pc;

	if (to_push->index <= to_push->target->index)
		pc = to_push->target->index;
	else
		pc = to_push->index;
	return (pc);
}

int	bpc_rrarrb(swp_list *a, swp_list *to_push, swp_list *b)
{
	swp_list	*tail_a;
	swp_list	*tail_b;
	int			rev_indexa;
	int			rev_indexb;

	tail_a = a;
	tail_b = b;
	while (tail_a->next)
		tail_a = tail_a->next;
	while (tail_b->next)
		tail_b = tail_b->next;
	rev_indexa = tail_a->index - to_push->target->index;
	rev_indexb = tail_b->index - to_push->index;
	if ((to_push->index == 0) && (to_push->target->index == 0))
		return (0);
	if (to_push->index == 0)
		return (rev_indexa + 1);
	else if (to_push->target->index == 0)
		return (rev_indexb + 1);
	else if ((rev_indexb <= rev_indexa))
		return (rev_indexa + 1);
	else
		return (rev_indexb + 1);
}

int	bpc_rarrb(swp_list *a, swp_list *to_push, swp_list *b)
{
	int			rev_indexb;
	swp_list	*tail_b;

	tail_b = b;
	while (tail_b->next)
		tail_b = tail_b->next;
	rev_indexb = tail_b->index - to_push->index;
	if (to_push->index == 0)
		return (to_push->target->index);
	return (to_push->target->index + rev_indexb + 1);
}

int	bpc_rrarb(swp_list *a, swp_list *to_push, swp_list *b)
{
	int			rev_indexa;
	swp_list	*tail_a;

	tail_a = a;
	while (tail_a->next)
		tail_a = tail_a->next;
	rev_indexa = tail_a->index - to_push->target->index;
	if (to_push->target->index == 0)
		return (to_push->index);
	return (to_push->index + rev_indexa + 1);
}
