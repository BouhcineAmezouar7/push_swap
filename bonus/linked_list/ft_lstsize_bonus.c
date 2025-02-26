/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:47:42 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/30 11:21:56 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/push_swap_bonus.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*k;
	int		i;

	k = lst;
	i = 0;
	while (k != NULL)
	{
		i++;
		k = k->next;
	}
	return (i);
}
