/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_args_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:47:28 by bamezoua          #+#    #+#             */
/*   Updated: 2025/02/02 10:24:20 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_double(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*next_tmp;

	tmp = *stack_a;
	while (tmp && tmp->next)
	{
		next_tmp = tmp->next;
		while (next_tmp)
		{
			if (tmp->content == next_tmp->content)
			{
				write(2, "Error\n", 6);
				cleanup(stack_a, NULL, NULL, NULL);
				exit(1);
			}
			next_tmp = next_tmp->next;
		}
		tmp = tmp->next;
	}
}

void	take_rank(int *tab, t_list **lst, int len)
{
	int		i;
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		i = 0;
		while (i < len)
		{
			if (tmp->content == tab[i])
				tmp->index = i;
			i++;
		}
		tmp = tmp->next;
	}
}

void	finalize_list(t_list *lst, int *tab, int len)
{
	if (lst)
		lst->len = len;
	ft_sort_int_tab(tab, len);
}

char	**process_argument(char *arg, t_list **lst)
{
	char	**arry;

	arry = ft_split(arg, ' ');
	if (!arry || !arry[0])
	{
		write(2, "Error\n", 6);
		cleanup(lst, NULL, arry, NULL);
		exit(EXIT_FAILURE);
	}
	if (!check_split_arg(arry, lst))
	{
		cleanup(lst, NULL, arry, NULL);
		exit(EXIT_FAILURE);
	}
	return (arry);
}

void	process_values(char **arry, t_list **lst, int *len)
{
	t_list	*new_node;
	int		j;
	int		value;

	j = 0;
	while (arry[j])
	{
		value = ft_atoi(arry[j], NULL, lst, arry);
		new_node = ft_lstnew(value);
		if (!new_node)
		{
			write(2, "Error\n", 6);
			cleanup(lst, NULL, arry, NULL);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(lst, new_node);
		(*len)++;
		j++;
	}
}
