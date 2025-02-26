/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:47:53 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/31 22:06:12 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stack(t_list *current)
{
	printf("Liste :\n");
	while (current)
	{
		printf("%d -> ", current->content);
		current = current->next;
	}
	printf("NULL\n");
}

void	sa(t_list **head)
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
	write(1, "sa\n", 3);
}

void	rotate(t_list **head, char stack_name)
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
	if (stack_name == 'a')
		write(1, "ra\n", 3);
	else if (stack_name == 'b')
		write(1, "rb\n", 3);
}

void	r_rotate(t_list **head, char stack_name)
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
	if (stack_name == 'a')
		write(1, "rra\n", 4);
	else if (stack_name == 'b')
		write(1, "rrb\n", 4);
}

void	push(t_list **dest, t_list **src, char stack_name)
{
	t_list	*first;

	if (!src || !*src)
		return ;
	first = *src;
	*src = (*src)->next;
	first->next = *dest;
	*dest = first;
	if (stack_name == 'a')
		write(1, "pa\n", 3);
	else if (stack_name == 'b')
		write(1, "pb\n", 3);
}
