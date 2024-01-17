/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:17:13 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/17 11:35:03 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pc_rarb(t_swp_list *a, t_swp_list *to_push, t_swp_list *b)
{
	int	pc;

	if (to_push->index <= to_push->target->index)
		pc = to_push->target->index;
	else
		pc = to_push->index;
	return (pc);
}

int	pc_rrarrb(t_swp_list *a, t_swp_list *to_push, t_swp_list *b)
{
	t_swp_list	*tail_a;
	t_swp_list	*tail_b;
	int			rev_indexa;
	int			rev_indexb;

	tail_a = a;
	tail_b = b;
	while (tail_a->next)
		tail_a = tail_a->next;
	while (tail_b->next)
		tail_b = tail_b->next;
	rev_indexa = tail_a->index - to_push->index;
	rev_indexb = tail_b->index - to_push->target->index;
	if ((to_push->index == 0) && (to_push->target->index == 0))
		return (0);
	if (to_push->index == 0)
		return (rev_indexb + 1);
	else if (to_push->target->index == 0)
		return (rev_indexa + 1);
	else if ((rev_indexb <= rev_indexa))
		return (rev_indexa + 1);
	else
		return (rev_indexb + 1);
}

int	pc_rarrb(t_swp_list *a, t_swp_list *to_push, t_swp_list *b)
{
	int			rev_indexb;
	t_swp_list	*tail_b;

	tail_b = b;
	while (tail_b->next)
		tail_b = tail_b->next;
	rev_indexb = tail_b->index - to_push->target->index;
	if (to_push->target->index == 0)
		return (to_push->index);
	return (to_push->index + rev_indexb + 1);
}

int	pc_rrarb(t_swp_list *a, t_swp_list *to_push, t_swp_list *b)
{
	int			rev_indexa;
	t_swp_list	*tail_a;

	tail_a = a;
	while (tail_a->next)
		tail_a = tail_a->next;
	rev_indexa = tail_a->index - to_push->index;
	if (to_push->index == 0)
		return (to_push->target->index);
	return (to_push->target->index + rev_indexa + 1);
}
