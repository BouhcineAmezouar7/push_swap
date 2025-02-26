/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:49:52 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/31 18:39:51 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	r_rotate(t_list **head)
{
	t_list	*first;
	t_list	*last;
	t_list	*new_last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	last = ft_lstlast(*head);
	new_last = *head;
	while (new_last->next != last)
		new_last = new_last->next;
	last->next = first;
	*head = last;
	new_last->next = NULL;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
}

void	push(t_list **dest, t_list **src)
{
	t_list	*first;

	if (!src || !*src)
		return ;
	first = *src;
	*src = (*src)->next;
	first->next = *dest;
	*dest = first;
}
