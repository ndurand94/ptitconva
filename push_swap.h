/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndurand <ndurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:27:05 by ndurand           #+#    #+#             */
/*   Updated: 2022/05/23 13:04:04 by ndurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_list
{
	void			*elem;
	struct s_list	*next;
}					t_list;

int				ft_nbrlen(long n, int base);
int				count_split_ac(char **str);
int				ft_atoi2(const char *nptr, long *nbr);
t_list			*ft_lstnew(void *elem);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *newnode);
void			ft_lstadd_front(t_list **lst, t_list *newnode);
void			ft_freelst(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
int				st_swap_ab(t_list **stack, char c);
int				st_swap_ss(t_list **a, t_list **b);
int				st_push_ab(t_list **a, t_list **b, char c);
int				st_rotate_ab(t_list **stack, char c);
int				st_rotate_rr(t_list **a, t_list **b);
int				st_rrotate_ab(t_list **stack, char c);
int				st_rrotate_rrr(t_list **a, t_list **b);
void			st_index(t_list **stack);
int				st_sort(t_list **a, t_list **b);
void			st_sort_3(t_list **a, t_list **b);
int				st_radix(t_list **a, t_list **b, int right_shift, int max_size);
int				st_get_sorted(t_list *a, t_list *b, char c);
void			*st_pop(t_list **stack);
int				st_push(t_list **stack, void *newelem, size_t size);
t_list			*st_newstack(void *newelem, size_t size);
int				st_find(t_list *stack, void *elem, size_t size);
int				st_is_ordered(t_list *stack);
int				st_top(t_list **stack, void *elem, char c);
int				ft_isspace(char c);
t_list			*st_min(t_list *stack);
t_list			*st_max(t_list *stack);
t_list			*st_get_at(t_list *stack, int index);
void			st_replace_at(t_list **stack, int index, void *nw, int size);

#endif
