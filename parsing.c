/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:11:26 by vabertau          #+#    #+#             */
/*   Updated: 2024/01/16 11:39:30 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_atoi(const char *nptr)
{
        int     i;
        int     ret;
        int     sign;

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
			if (atoi(splitted[i]) == atoi(splitted[j]))
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
	if (argc == 1 || !argv[1])
	{
		write(2, "Error\n", 6);
		return (-1);
	}
        if (argc == 2)
                splitted = ft_split(argv[1], 2);
	if (argc == 2)
	{
		if (duplicates(splitted))
			error = 1;
	}
	else
	{
		if (duplicates(argv))
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
