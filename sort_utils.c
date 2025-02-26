/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 22:18:14 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/31 22:19:26 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *head)
{
	int	max;

	if (!head)
		return (0);
	max = head->content;
	while (head)
	{
		if (head->content > max)
			max = head->content;
		head = head->next;
	}
	return (max);
}

int	find_min(t_list *head)
{
	int	min;

	if (!head)
		return (0);
	min = head->content;
	while (head)
	{
		if (head->content < min)
			min = head->content;
		head = head->next;
	}
	return (min);
}

int	find_min_index(t_list *head, int min)
{
	int	index;

	index = 0;
	while (head)
	{
		if (head->content == min)
			break ;
		head = head->next;
		index++;
	}
	return (index);
}

void	push_back(t_list **stack_a, t_list **stack_b)
{
	int	max;
	int	max_index;
	int	size;

	while (*stack_b)
	{
		size = ft_lstsize(*stack_b);
		max = find_max(*stack_b);
		max_index = find_min_index(*stack_b, max);
		if (max_index <= size / 2)
		{
			while ((*stack_b)->content != max)
				rotate(stack_b, 'b');
		}
		else
		{
			while ((*stack_b)->content != max)
				r_rotate(stack_b, 'b');
		}
		push(stack_a, stack_b, 'a');
	}
}
