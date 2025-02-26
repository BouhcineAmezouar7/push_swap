/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_leaks_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:50:15 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/31 18:59:08 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_stack(t_list **stack)
{
	t_list	*temp;
	t_list	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	cleanup(t_list **stack_a, t_list **stack_b, char **split, int *tab)
{
	if (stack_a)
		ft_lstclear(stack_a);
	if (stack_b)
		ft_lstclear(stack_b);
	if (tab)
		free(tab);
	if (split)
		free_split(split);
	exit(1);
}

void	free_main(char *buffer, t_list **stack_a, t_list **stack_b)
{
	write(2, "Error\n", 6);
	free(buffer);
	cleanup(stack_a, stack_b, NULL, NULL);
	exit(1);
}
