/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:49:52 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/31 18:40:14 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_list **head)
{
	t_list	*first;
	t_list	*second;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	rotate(t_list **head)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	last = ft_lstlast(*head);
	last->next = first;
	*head = second;
	first->next = NULL;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
