/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:35:11 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/16 19:21:41 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rab(swp_list **a, int print)
{
	swp_list	*tail;
	swp_list	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tail = *a;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = tmp;
	tmp->next = NULL;
	if (print == 1)
		write (1, "ra\n", 3);
	if (print == 2)
		write (1, "rb\n", 3);
	return (0);
}

int	rr(swp_list **a, swp_list **b)
{
	rab(a, 0);
	rab(b, 0);
	write (1, "rr\n", 3);
	return (0);
}

int	rrab(swp_list **a, int op)
{
	swp_list	*tail;
	swp_list	*pretail;

	tail = *a;
	while (tail->next != NULL)
	{
		pretail = tail;
		tail = tail->next;
	}
	tail->next = *a;
	*a = tail;
	pretail->next = NULL;
	if (op == 1)
		write (1, "rra\n", 4);
	if (op == 2)
		write (1, "rrb\n", 4);
	return (0);
}

int	rrr(swp_list **a, swp_list **b)
{
	rrab(a, 0);
	rrab(b, 0);
	write (1, "rrr\n", 4);
	return (0);
}

int	sab(swp_list **a, int op)
{
	swp_list	*tmp;
	swp_list	*tmp2;

	tmp = *a;
	tmp2 = (*a)->next->next;
	*a = (*a)->next;
	(*a)->next = tmp;
	tmp->next = tmp2;
	if (op == 1)
		write (1, "sa\n", 3);
	if (op == 2)
		write (1, "sb\n", 3);
	return (0);
}
/* ================== TEST OPS ===================*/

/*
#include <stdio.h>

int     main(int argc, char **argv)
{
        swp_list        **a;
        swp_list        **b;
	swp_list	*tmp;

        a = malloc(sizeof(swp_list *));
        b = malloc(sizeof(swp_list *));
        *a = NULL;
        *b = NULL;

        cr_stacks(a, b, argc, argv);
	ft_lstadd_back(b, ft_lstnew(8));//adding elements in stack b for test
        printf("%i args\n", argc); // to suppress
	tmp = *a;
	while (tmp)
        {
                printf("number = %li\n", tmp->nbr);
                tmp = tmp->next;
        }
	//rab(a);
	//printf("ra executed\n");
	//rrab(a);
	//printf("rra executed\n");
	//sab(a);
	//printf("sa executed\n");
	//pb(a, b);
	//printf("pb executed\n");
	pa(a, b);
        printf("pa executed\n");	
        while (*a)
        {
                printf("number = %li\n", (*a)->nbr);
                *a = (*a)->next;
        }
	while (*b)
        {
                printf("number b = %li\n", (*b)->nbr);
                *b = (*b)->next;
        }	
        return (0);
}*/
