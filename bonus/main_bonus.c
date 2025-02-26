/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:39:52 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/31 18:58:36 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	check_operations(char *buffer, t_list **stack_a, t_list **stack_b)
{
	if (buffer && ft_strcmp(buffer, "sa\n") == 0)
		swap(stack_a);
	else if (buffer && ft_strcmp(buffer, "sb\n") == 0)
		swap(stack_b);
	else if (buffer && ft_strcmp(buffer, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (buffer && ft_strcmp(buffer, "ra\n") == 0)
		rotate(stack_a);
	else if (buffer && ft_strcmp(buffer, "rb\n") == 0)
		rotate(stack_b);
	else if (buffer && ft_strcmp(buffer, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (buffer && ft_strcmp(buffer, "rra\n") == 0)
		r_rotate(stack_a);
	else if (buffer && ft_strcmp(buffer, "rrb\n") == 0)
		r_rotate(stack_b);
	else if (buffer && ft_strcmp(buffer, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else if (buffer && ft_strcmp(buffer, "pa\n") == 0)
		push(stack_a, stack_b);
	else if (buffer && ft_strcmp(buffer, "pb\n") == 0)
		push(stack_b, stack_a);
	else
		free_main(buffer, stack_a, stack_b);
	free(buffer);
}

void	check(t_list **stack_a, t_list **stack_b)
{
	char	*buffer;

	buffer = get_next_line(0);
	while (buffer)
	{
		check_operations(buffer, stack_a, stack_b);
		buffer = get_next_line(0);
	}
}

int	is_sorted(t_list *stack_a, t_list *stack_b)
{
	int	size;

	size = ft_lstsize(stack_b);
	if (size > 0 && stack_b != NULL)
		return (0);
	while (stack_a && stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = handel_error(ac, av);
	check_double(&stack_a);
	if (!stack_a)
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		exit(0);
	}
	check(&stack_a, &stack_b);
	if (is_sorted(stack_a, stack_b) == 1)
		write(2, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	cleanup(&stack_a, &stack_b, NULL, NULL);
	return (0);
}
