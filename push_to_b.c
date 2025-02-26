/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 22:07:02 by bamezoua          #+#    #+#             */
/*   Updated: 2025/02/02 11:57:06 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_push_vars(t_var *var, int len)
{
	var->start = 0;
	if (len <= 100)
		var->end = len / 5;
	else if (len <= 500)
		var->end = len / 12;
}

void	push_within_range(t_list **stack_a, t_list **stack_b, t_var *var,
		int len)
{
	if ((*stack_a)->index <= var->start)
	{
		push(stack_b, stack_a, 'b');
		rotate(stack_b, 'b');
		if (var->end <= len)
			var->end++;
		if (var->start < var->end)
			var->start++;
	}
	else if ((*stack_a)->index <= var->end)
	{
		push(stack_b, stack_a, 'b');
		if (var->end <= len)
			var->end++;
		if (var->start < var->end)
			var->start++;
	}
	else
		rotate(stack_a, 'a');
}

void	push_to_b(t_list **stack_a, t_list **stack_b, int len)
{
	t_var	var;

	init_push_vars(&var, len);
	while ((*stack_a))
	{
		push_within_range(stack_a, stack_b, &var, len);
	}
}
