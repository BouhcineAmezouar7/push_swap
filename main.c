/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 22:18:46 by bamezoua          #+#    #+#             */
/*   Updated: 2025/02/02 10:06:58 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	handle_empty_or_sorted(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a)
	{
		cleanup(stack_a, stack_b, NULL, NULL);
		exit(0);
	}
	if (is_sorted(*stack_a))
	{
		cleanup(stack_a, stack_b, NULL, NULL);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = handel_error(ac, av);
	check_double(&stack_a);
	if (handle_empty_or_sorted(&stack_a, &stack_b))
		return (0);
	if (stack_a->len == 2 && stack_a->content > stack_a->next->content)
		sa(&stack_a);
	else if (stack_a->len == 3)
		sort_3(&stack_a);
	else if (stack_a->len == 4)
		sort_4(&stack_a, &stack_b);
	else if (stack_a->len == 5)
		sort_5(&stack_a, &stack_b);
	else
		sort_pro_max(&stack_a, &stack_b, stack_a->len);
	cleanup(&stack_a, &stack_b, NULL, NULL);
	return (0);
}
