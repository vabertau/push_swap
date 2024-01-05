/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:26:13 by vabertau          #+#    #+#             */
/*   Updated: 2023/12/25 17:42:09 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

swp_list        *ft_lstnew(long nbr)
{
        swp_list        *ret;

        ret = malloc(sizeof(swp_list));
        if (!ret)
                return (NULL);
        ret->nbr = nbr;
        ret->next = NULL;
        return (ret);
}

swp_list        *ft_lstlast(swp_list *a)
{
        swp_list        *tmp;

        tmp = a;
        if (a)
        {
                while (tmp->next)
                        tmp = tmp->next;
        }
        return (tmp);
}

void    ft_lstadd_back(swp_list **a, swp_list *new)
{
        swp_list        *last;

        if (!new)
                return ;
        if (*a)
        {
                last = ft_lstlast(*a);
                last->next = new;
        }
        else
                *a = new;
}

