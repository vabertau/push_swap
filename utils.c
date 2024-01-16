/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:01:22 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/16 19:07:13 by vabertau         ###   ########.fr       */
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

swp_list        *find_biggest(swp_list *a)
{
        swp_list        *ret;

        ret = a;
        while (a)
        {
                if (a->nbr > ret->nbr)
                        ret = a;
                a = a->next;
        }
        return (ret);
}

int     find_index(swp_list *a, swp_list *needle)
{
        int     ret;

        ret = 0;
        while (a)
        {
                if (a == needle)
                        return (ret);
                ret++;
                a = a->next;
        }
        return (-1);
}

int     above_median(swp_list *head, int index_topush)
{
        int     nb_is;

        nb_is = howmany_instack(head);
        if (index_topush <= (nb_is / 2))
                return (0);
        else
                return (1);
}
