/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:52:58 by bamezoua          #+#    #+#             */
/*   Updated: 2025/02/02 11:11:40 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../get_next_line/get_next_line.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				index;
	int				len;
	char			**arry;
}					t_list;

int					ft_lstsize(t_list *lst);
t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				show_stack(t_list *current);
void				rotate(t_list **head);
void				swap(t_list **head);
void				r_rotate(t_list **head);
t_list				*handel_error(int ac, char **av);
int					ft_atoi(const char *str, int *tab, t_list **lst,
						char **arry);
char				**ft_split(char const *s, char c);
void				sort_3(t_list **stack_a);
void				sort_4(t_list **stack_a, t_list **stack_b);
int					find_max(t_list *head);
int					find_min(t_list *head);
void				push(t_list **dest, t_list **src);
void				check_double(t_list **stack_a);
void				sort_5(t_list **stack_a, t_list **stack_b);
void				free_stack(t_list **stack);
void				cleanup(t_list **stack_a, t_list **stack_b, char **split,
						int *tab);
void				free_split(char **split_array);
void				ft_sort_int_tab(int *tab, int size);
void				ft_lstclear(t_list **lst);
void				take_rank(int *tab, t_list **lst, int len);
void				sort_pro_max(t_list **stack_a, t_list **stack_b, int len);
int					is_sorted(t_list *stack_a, t_list *stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				finalize_list(t_list *lst, int *tab, int len);
char				**process_argument(char *arg, t_list **lst);
void				process_values(char **arry, t_list **lst, int *len);
void				free_main(char *buffer, t_list **stack_a, t_list **stack_b);
int					check_split_arg(char **arry, t_list **lst);
#endif
