/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:43:30 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/17 14:13:21 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	check_input(int argc, char **argv)
{
	if (argc == 1)
		return (write(2, "Error \n", 7), -1);
	return (0);
}

void	free_tabs(char **split_sep, long *sep_long, char **argv)
{
	int	i;

	i = 0;
	if (split_sep != &(argv[1]))
	{
		while (split_sep[i])
		{
			free(split_sep[i]);
			i++;
		}
		free (split_sep);
	}
	free (sep_long);
}

int	cr_lists(t_swp_list ***a, t_swp_list ***b)
{
        *a = malloc(sizeof(t_swp_list *));
        if (!(*a))
		return (-1);
	*b = malloc(sizeof(t_swp_list *));
	if (!(*b))
		return (free(*a), -1);
        **a = NULL;
        **b = NULL;
	return (0);
}

int	cr_stacks(t_swp_list **a, t_swp_list **b, int argc, char **argv)
{
	char	**split_sep;
	long	*sep_long;
	int		i;
	int		nb_arg;

	i = 0;
	nb_arg = 0;
	if (argc == 2)
		split_sep = ft_split(argv[1], ' ');
	else
		split_sep = &(argv[1]);
	while (split_sep[nb_arg])
		nb_arg++;
	sep_long = malloc(sizeof(long) * nb_arg);
	if (!sep_long)
		return (-1);
	while (split_sep[i])
	{	
		sep_long[i] = atoi(split_sep[i]);
		ft_lstadd_back(a, ft_lstnew(sep_long[i]));
		i++;
	}
	return (free_tabs(split_sep, sep_long, argv), 0);
}
/*
int	main(int argc, char **argv)
{
	t_swp_list	**a;
	t_swp_list	**b;
	
	a = malloc(sizeof(t_swp_list *));
	b = malloc(sizeof(t_swp_list *));
	*a = NULL;
	*b = NULL;
	//long	parsed_args[] = {1, 2, 3, 4}; //to test

	if (check_input(argc, argv) == -1)
	       return (-1);	// check input to complete
	cr_stacks(a, b, argc, argv);
	printf("%i args\n", argc); // to suppress
	//printf("sorted? = %i\n", stack_sorted(*a));//to supress
	//sortall(a, b);	
	while (*a)
	{
		printf("number = %li\n", (*a)->nbr);
	       	*a = (*a)->next;
	}	
	return (0);
}
*/
/* ==================== Test parse_input =============== */
/*
int	main(int argc, char **argv)
{
	long	*input;
	int	i;

	i = 0;
	input = parse_input(argc, argv);
	while (i < 5)
	{
		printf("input %i = %li\n", i+1, input[i]);
		i++;
	}
}*/
