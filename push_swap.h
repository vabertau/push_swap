/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:14:50 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/15 18:12:16 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"

// a->op : 1=rarb 2=rrarrb 3=rarrb 4=rrarb

typedef struct	swp_list
{
	long			nbr;
	struct	swp_list	*next;
	struct	swp_list	*target;
	int			index;
	int			push_cost;
	int			is_cheapest;
	int			op;
}	swp_list;

// Utils linked lists

swp_list	*ft_lstlast(swp_list *a);
swp_list	*ft_lstnew(long nbr);
void		ft_lstadd_back(swp_list **a, swp_list *new);
swp_list        *find_lowest(swp_list *a);
int		above_median(swp_list *head, int index_topush);

// Sorting

int     sortall(swp_list **a, swp_list **b);
int     sort2(swp_list **a);
int     sort3(swp_list **a);
// Node init

int     set_allindex(swp_list *a, swp_list *b);
int     find_index(swp_list *a, swp_list *needle);
int     push_cost(swp_list *a, swp_list *b);
int     binit_nodes(swp_list **a, swp_list **b);
int     set_cheapest(swp_list *a, swp_list *b);

// Stack manipulation

int     howmany_instack(swp_list *a);
int     cr_stacks(swp_list **a, swp_list **b, int argc, char **argv);
int     stack_sorted(swp_list *a);
int     init_nodes(swp_list **a, swp_list **b);
int     minus_tobottom(swp_list **a);

// Operations executers

int     rab(swp_list **a, int print);
int     rr(swp_list **a, swp_list **b);
int     rrab(swp_list **a, int op);
int     rrr(swp_list **a, swp_list **b);
int     sab(swp_list **a, int op);
int     ss(swp_list **a, swp_list **b);
int     pb(swp_list **a, swp_list **b);
int     pa(swp_list **a, swp_list **b);

int     exec_allbtoa(swp_list **a, swp_list **b);

// Push_cost based on ops choice

int     pc_rarb(swp_list *a, swp_list *to_push, swp_list *b);
int     pc_rrarrb(swp_list *a, swp_list *to_push, swp_list *b);
int	pc_rarrb(swp_list *a, swp_list *to_push, swp_list *b);
int	pc_rrarb(swp_list *a, swp_list *to_push, swp_list *b);

int     bpc_rarb(swp_list *a, swp_list *to_push, swp_list *b);
int     bpc_rrarrb(swp_list *a, swp_list *to_push, swp_list *b);
int     bpc_rarrb(swp_list *a, swp_list *to_push, swp_list *b);
int     bpc_rrarb(swp_list *a, swp_list *to_push, swp_list *b);

#endif
