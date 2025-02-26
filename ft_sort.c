/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:55:55 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/31 22:05:40 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	if (stack_a && (*stack_a)->content == find_max(*stack_a))
		rotate(stack_a, 'a');
	if (stack_a && (*stack_a)->next
		&& (*stack_a)->next->content == find_max(*stack_a))
		r_rotate(stack_a, 'a');
	if (stack_a && (*stack_a)->next
		&& (*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	min_val;
	int	min_index;
	int	size;

	size = ft_lstsize(*stack_a);
	while (size-- > 3)
	{
		min_val = find_min(*stack_a);
		min_index = find_min_index(*stack_a, min_val);
		if (min_index <= size / 2)
		{
			while ((*stack_a)->content != min_val)
				rotate(stack_a, 'a');
		}
		else
		{
			while ((*stack_a)->content != min_val)
				r_rotate(stack_a, 'a');
		}
		push(stack_b, stack_a, 'b');
	}
	sort_3(stack_a);
	push(stack_a, stack_b, 'a');
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	min_val;
	int	min_index;
	int	size;

	size = ft_lstsize(*stack_a);
	while (size-- > 3)
	{
		min_val = find_min(*stack_a);
		min_index = find_min_index(*stack_a, min_val);
		if (min_index <= size / 2)
		{
			while ((*stack_a)->content != min_val)
				rotate(stack_a, 'a');
		}
		else
		{
			while ((*stack_a)->content != min_val)
				r_rotate(stack_a, 'a');
		}
		push(stack_b, stack_a, 'b');
	}
	sort_4(stack_a, stack_b);
	push(stack_a, stack_b, 'a');
}

void	sort_pro_max(t_list **stack_a, t_list **stack_b, int len)
{
	push_to_b(stack_a, stack_b, len);
	push_back(stack_a, stack_b);
}
