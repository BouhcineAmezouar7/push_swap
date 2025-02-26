/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:56:07 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/31 22:08:00 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_whitespace_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= '\t' && str[*i] <= '\r'))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str, int *tab, t_list **lst, char **arry)
{
	int		i;
	long	nbr;
	int		s;

	i = 0;
	nbr = 0;
	s = check_whitespace_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		if ((nbr * s) > INT_MAX || (nbr * s) < INT_MIN)
		{
			write(2, "Error\n", 6);
			cleanup(lst, NULL, arry, tab);
		}
		i++;
	}
	if (str[i])
	{
		write(2, "Error\n", 6);
		cleanup(lst, NULL, arry, tab);
	}
	return (nbr * s);
}
