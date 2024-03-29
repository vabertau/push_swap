/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_atobmain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:10:45 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/17 11:35:32 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_1atob(t_swp_list **a, t_swp_list **b)
{
	t_swp_list	*to_push;

	to_push = *a;
	init_nodes(a, b);
	while (to_push)
	{
		if (to_push->is_cheapest == 1)
		{
			if (to_push->op == 1)
				exec_rarb(a, &to_push, b);
			else if (to_push->op == 2)
				exec_rrarrb(a, &to_push, b);
			else if (to_push->op == 3)
				exec_rarrb(a, &to_push, b);
			else if (to_push->op == 4)
				exec_rrarb(a, &to_push, b);
			return (0);
		}
		to_push = to_push->next;
	}
	return (0);
}

int	exec_allatob(t_swp_list **a, t_swp_list **b)
{
	if (howmany_instack(*a) > 3)
		pb(a, b);
	if (howmany_instack(*a) > 3)
		pb(a, b);
	while (howmany_instack(*a) > 3)
		exec_1atob(a, b);
	return (0);
}
/*
int     main(int argc, char **argv)
{
	t_swp_list        **a;
        t_swp_list        **b;
        t_swp_list        *tmp;

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
        while (tmp)
        {
                printf("number bf s3 = %li:\nindexa = %i\n\n",
		(tmp)->nbr, (tmp)->index);//testing target nodes
                tmp = (tmp)->next;
        }*/
	/*sort3(a);
        exec_allbtoa(a, b);
        minus_tobottom(a);*/
	/*printf("\n====PROGRAM ENDED====\n");
        while (*a)
        {
                printf("number = %li:\nindexa = %i\n\n",
		(*a)->nbr, (*a)->index);//testing target nodes
                *a = (*a)->next;
        }       
        while (*b)
        {
                printf("number b = %li\n", (*b)->nbr);
                *b = (*b)->next;
        }*/
	//return (0);
/*
        while (*a)
        {
                printf("number = %li:\ntarget node = %li\n
		indexa = %i\nindexb = %i\n
		push_cost = %i\nis_cheapest = %i\n\n", (*a)->nbr, (*a)->target->nbr,
		(*a)->index, (*a)->target->index, (*a)->push_cost,
		(*a)->is_cheapest);//testing target nodes
                *a = (*a)->next;
        }
        while (*b)
        {
                printf("number b = %li\n", (*b)->nbr);
                *b = (*b)->next;
        }
        return (0);*/
//}
