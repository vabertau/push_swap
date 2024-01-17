/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:13:22 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/17 11:36:32 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_swp_list	**a;
	t_swp_list	**b;
	t_swp_list	*tmp;

	a = malloc(sizeof(t_swp_list *));
	b = malloc(sizeof(t_swp_list *));
	*a = NULL;
	*b = NULL;
	if (parsing(argc, argv) == -1)
		return (-1);
	cr_stacks(a, b, argc, argv);
	if (howmany_instack(*a) == 1)
		return (0);
	if (howmany_instack(*a) == 2)
	{
		sort2(a);
		return (0);
	}
	exec_allatob(a, b);
	tmp = *a;
	sort3(a);
	exec_allbtoa(a, b);
	minus_tobottom(a);
	return (0);
}
