/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:13:22 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/17 14:25:05 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_swp_list	**a;
	t_swp_list	**b;
	t_swp_list	*tmp;

	if ((cr_lists(&a, &b) == -1))
		return (write(2, "Error\n", 6), -1);
	if (parsing(argc, argv) == -1)
		return (free_list(a), free_list(b), -1);
	cr_stacks(a, b, argc, argv);
	if (howmany_instack(*a) == 1)
		return (free_list(a), free_list(b), 0);
	if (howmany_instack(*a) == 2)
	{
		sort2(a);
		return (free_list(a), free_list(b), 0);
	}
	exec_allatob(a, b);
	tmp = *a;
	sort3(a);
	exec_allbtoa(a, b);
	minus_tobottom(a);
	return (free_list(a), free_list(b), 0);
}
