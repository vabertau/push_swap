/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:14:50 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/17 12:12:22 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

// a->op : 1=rarb 2=rrarrb 3=rarrb 4=rrarb

typedef struct swp_list
{
	long			nbr;
	struct swp_list	*next;
	struct swp_list	*target;
	int				index;
	int				push_cost;
	int				is_cheapest;
	int				op;
}	t_swp_list;

// Utils linked lists

t_swp_list	*ft_lstlast(t_swp_list *a);
t_swp_list	*ft_lstnew(long nbr);
void		ft_lstadd_back(t_swp_list **a, t_swp_list *new);
t_swp_list	*find_lowest(t_swp_list *a);
int			above_median(t_swp_list *head, int index_topush);

// Parsing

int			parsing(int argc, char **argv);

// Sorting

int			sortall(t_swp_list **a, t_swp_list **b);
int			sort2(t_swp_list **a);
int			sort3(t_swp_list **a);

// Node init

int			set_allindex(t_swp_list *a, t_swp_list *b);
int			push_cost(t_swp_list *a, t_swp_list *b);
int			binit_nodes(t_swp_list **a, t_swp_list **b);
int			set_cheapest(t_swp_list *a, t_swp_list *b);

// Utils

int			get_revindex(t_swp_list **a, t_swp_list **to_push);
t_swp_list	*find_biggest(t_swp_list *a);
int			find_index(t_swp_list *a, t_swp_list *needle);
int			ft_atol(const char *nptr);
int			howmany_instack(t_swp_list *a);
int			free_doubletab(char **tab);
int			free_list(t_swp_list **a);
// Stack manipulation

int			howmany_instack(t_swp_list *a);
int			cr_stacks(t_swp_list **a, t_swp_list **b, int argc, char **argv);
int			stack_sorted(t_swp_list *a);
int			init_nodes(t_swp_list **a, t_swp_list **b);
int			minus_tobottom(t_swp_list **a);

// Operations executers

int			rab(t_swp_list **a, int print);
int			rr(t_swp_list **a, t_swp_list **b);
int			rrab(t_swp_list **a, int op);
int			rrr(t_swp_list **a, t_swp_list **b);
int			sab(t_swp_list **a, int op);
int			ss(t_swp_list **a, t_swp_list **b);
int			pb(t_swp_list **a, t_swp_list **b);
int			pa(t_swp_list **a, t_swp_list **b);

int			exec_allatob(t_swp_list **a, t_swp_list **b);
int			exec_allbtoa(t_swp_list **a, t_swp_list **b);
int			exec_rarb(t_swp_list **a, t_swp_list **to_push, t_swp_list **b);
int			exec_rrarrb(t_swp_list **a, t_swp_list **to_push, t_swp_list **b);
int			exec_rarrb(t_swp_list **a, t_swp_list **to_push, t_swp_list **b);
int			exec_rrarb(t_swp_list **a, t_swp_list **to_push, t_swp_list **b);
int			bexec_rrarrb(t_swp_list **a, t_swp_list **to_push, t_swp_list **b);

// Push_cost based on ops choice

int			pc_rarb(t_swp_list *a, t_swp_list *to_push, t_swp_list *b);
int			pc_rrarrb(t_swp_list *a, t_swp_list *to_push, t_swp_list *b);
int			pc_rarrb(t_swp_list *a, t_swp_list *to_push, t_swp_list *b);
int			pc_rrarb(t_swp_list *a, t_swp_list *to_push, t_swp_list *b);

int			bpc_rarb(t_swp_list *a, t_swp_list *to_push, t_swp_list *b);
int			bpc_rrarrb(t_swp_list *a, t_swp_list *to_push, t_swp_list *b);
int			bpc_rarrb(t_swp_list *a, t_swp_list *to_push, t_swp_list *b);
int			bpc_rrarb(t_swp_list *a, t_swp_list *to_push, t_swp_list *b);

#endif
