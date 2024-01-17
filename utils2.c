/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:47:29 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/17 13:58:27 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	howmany_instack(t_swp_list *a)
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

int	free_doubletab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

int	free_list(t_swp_list **a)
{
	t_swp_list	*tmp;
	t_swp_list	*cursor;

	cursor = *a;
	while (cursor)
	{
		tmp = cursor;
		cursor = cursor->next;
		free(tmp);
	}
	free(a);
	return (0);
}
