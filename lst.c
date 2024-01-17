/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:26:13 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/17 11:36:14 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swp_list	*ft_lstnew(long nbr)
{
	t_swp_list	*ret;

	ret = malloc(sizeof(t_swp_list));
	if (!ret)
		return (NULL);
	ret->nbr = nbr;
	ret->next = NULL;
	return (ret);
}

t_swp_list	*ft_lstlast(t_swp_list *a)
{
	t_swp_list	*tmp;

	tmp = a;
	if (a)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	return (tmp);
}

void	ft_lstadd_back(t_swp_list **a, t_swp_list *new)
{
	t_swp_list	*last;

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
