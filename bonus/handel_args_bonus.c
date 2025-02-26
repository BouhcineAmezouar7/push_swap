/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_args_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:40:39 by bamezoua          #+#    #+#             */
/*   Updated: 2025/02/02 10:24:01 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	error(char **arry, t_list **lst)
{
	write(2, "Error\n", 6);
	cleanup(lst, NULL, arry, NULL);
	exit(1);
}

int	check_split_arg(char **arry, t_list **lst)
{
	int	i;
	int	j;

	i = 0;
	while (arry[i])
	{
		if (arry[i][0] == '\0')
			error(arry, lst);
		j = 0;
		while (arry[i][j])
		{
			if (arry[i][j] == '-' || arry[i][j] == '+')
			{
				if (j > 0 || !(arry[i][j + 1] >= '0' && arry[i][j + 1] <= '9'))
					error(arry, lst);
			}
			else if (arry[i][j] < '0' || arry[i][j] > '9')
				error(arry, lst);
			j++;
		}
		i++;
	}
	return (1);
}

int	*initialize_tab(t_list *lst, int len)
{
	int		*tab;
	int		i;
	t_list	*temp;

	tab = malloc(sizeof(int) * len);
	if (!tab)
	{
		write(2, "Error\n", 6);
		cleanup(&lst, NULL, NULL, NULL);
		exit(EXIT_FAILURE);
	}
	temp = lst;
	i = 0;
	while (temp)
	{
		tab[i++] = temp->content;
		temp = temp->next;
	}
	return (tab);
}

t_list	*handel_error(int ac, char **av)
{
	t_list	*lst;
	int		*tab;
	int		len;
	char	**arry;
	int		i;

	lst = NULL;
	len = 0;
	i = 1;
	while (i < ac)
	{
		arry = process_argument(av[i], &lst);
		process_values(arry, &lst, &len);
		free_split(arry);
		i++;
	}
	tab = initialize_tab(lst, len);
	finalize_list(lst, tab, len);
	take_rank(tab, &lst, len);
	free(tab);
	return (lst);
}
