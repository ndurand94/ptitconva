/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndurand <ndurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:44:34 by ndurand           #+#    #+#             */
/*   Updated: 2022/05/20 16:53:27 by ndurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	st_sort(t_list **a, t_list **b)
{
	int	max_value;

	max_value = ft_lstsize(*a) - 1;
	if (st_is_ordered(*a))
		return (0);
	if (max_value + 1 == 2)
		return (st_swap_ab(a, 'a'));
	st_index(a);
	while (ft_lstsize(*a) > 3 && ft_lstsize(*a) < 7)
	{
		st_top(a, st_min(*a)->elem, 'a');
		st_push_ab(b, a, 'b');
	}
	st_sort_3(a, b);
	if (!st_is_ordered(*a))
		st_radix(a, b, ft_nbrlen(max_value, 2), 0);
	return (0);
}

void	st_sort_3(t_list **a, t_list **b)
{
	if (*(int *)st_get_at(*a, 1)->elem == *(int *)st_min(*a)->elem && \
		*(int *)st_get_at(*a, 2)->elem == *(int *)st_max(*a)->elem)
		st_swap_ab(a, 'a');
	if (*(int *)st_get_at(*a, 1)->elem == *(int *)st_min(*a)->elem && \
		*(int *)st_get_at(*a, 0)->elem == *(int *)st_max(*a)->elem)
		st_rotate_ab(a, 'a');
	if (*(int *)st_get_at(*a, 2)->elem == *(int *)st_min(*a)->elem && \
		*(int *)st_get_at(*a, 1)->elem == *(int *)st_max(*a)->elem)
		st_rrotate_ab(a, 'a');
	if (*(int *)st_get_at(*a, 0)->elem == *(int *)st_min(*a)->elem && \
		*(int *)st_get_at(*a, 1)->elem == *(int *)st_max(*a)->elem)
	{
		st_swap_ab(a, 'a');
		st_rotate_ab(a, 'a');
	}
	if (*(int *)st_get_at(*a, 2)->elem == *(int *)st_min(*a)->elem && \
		*(int *)st_get_at(*a, 0)->elem == *(int *)st_max(*a)->elem)
	{
		st_swap_ab(a, 'a');
		st_rrotate_ab(a, 'a');
	}
	while (ft_lstsize(*b))
		st_push_ab(a, b, 'a');
}

int	st_radix(t_list **a, t_list **b, int max_len, int right_shift)
{
	int	i;
	int	len;
	int	limit;

	if (right_shift > max_len || st_is_ordered(*a))
	{
		while (ft_lstsize(*b))
			st_push_ab(a, b, 'a');
		return (0);
	}
	i = -1;
	len = ft_lstsize(*a);
	limit = st_get_sorted(*a, *b, 'a');
	while (++i < len - limit && !st_is_ordered(*a))
	{
		if (!(*(int *)(*a)->elem >> right_shift & 1))
			st_push_ab(b, a, 'b');
		else
			st_rotate_ab(a, 'a');
	}
	i = -1;
	len = ft_lstsize(*b);
	while (++i < len - st_get_sorted(*a, *b, 'b'))
		st_push_ab(a, b, 'a');
	return (st_radix(a, b, max_len, right_shift + 1));
}
