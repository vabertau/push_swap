/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:01:22 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/17 11:37:48 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_revindex(t_swp_list **a, t_swp_list **to_push)
{
	t_swp_list	*tail_a;

	tail_a = *a;
	while (tail_a->next)
		tail_a = tail_a->next;
	return (tail_a->index - (*to_push)->index);
}

t_swp_list	*find_biggest(t_swp_list *a)
{
	t_swp_list	*ret;

	ret = a;
	while (a)
	{
		if (a->nbr > ret->nbr)
			ret = a;
		a = a->next;
	}
	return (ret);
}

int	find_index(t_swp_list *a, t_swp_list *needle)
{
	int	ret;

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

int	above_median(t_swp_list *head, int index_topush)
{
	int	nb_is;

	nb_is = howmany_instack(head);
	if (index_topush <= (nb_is / 2))
		return (0);
	else
		return (1);
}

int	ft_atol(const char *nptr)
{
	long long	i;
	long long	ret;
	int			sign;

	i = 0;
	ret = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ret = ret * 10 + nptr[i] - 48;
		i++;
	}
	return (ret * sign);
}
