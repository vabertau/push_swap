/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:01:22 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/16 19:02:09 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     get_revindex(swp_list **a, swp_list **to_push)
{
	swp_list	*tail_a;

	tail_a = *a;
	while (tail_a->next)
		tail_a = tail_a->next;
	return (tail_a->index - (*to_push)->index);
}
