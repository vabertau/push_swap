/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:11:26 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/16 12:08:14 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicates(char **splitted)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (splitted[i])
	{
		j = i + 1;
		while (splitted[j])
		{
			if (ft_atoi(splitted[i]) == ft_atoi(splitted[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_notint(char **splitted)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (splitted[i])
	{
		j = 0;
		while (splitted[i][j])
		{
			if (!(splitted[i][j] >= '0' && splitted[i][j] <= '9')
					&& splitted[i][j] != ' ' && splitted[i][j] != '-'
						&& splitted[i][j] != '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parsing(int argc, char **argv)
{
	char	**splitted;
	int	error;

	error = 0;
	if (argc == 1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
        if (argc == 2)
                splitted = ft_split(argv[1], 2);
	if (argc == 2)
	{
		if (duplicates(splitted) || error_notint(splitted))
			error = 1;
	}
	else
	{
		if (duplicates(&(argv[1])) || error_notint(&(argv[1])))
			error = 1;
	}
	free (splitted);
	if (error == 1)
	{
		write(2, "Error\n",6);
		return (-1);
	}
	return (0);
}
