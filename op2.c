/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndurand <ndurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:14:08 by ndurand           #+#    #+#             */
/*   Updated: 2022/05/20 16:53:27 by ndurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	st_swap_ab(t_list **stack, char c)
{
	void	*temp;
	t_list	*head;

	head = *stack;
	if (ft_lstsize(*stack) > 1)
	{
		temp = head->elem;
		head->elem = head->next->elem;
		head->next->elem = temp;
		if (c == 'a')
			ft_putstr_fd("sa\n", 1);
		if (c == 'b')
			ft_putstr_fd("sb\n", 1);
		return (1);
	}
	return (0);
}

int	st_push_ab(t_list **a, t_list **b, char c)
{
	void	*temp;

	if (ft_lstsize(*b))
	{
		temp = st_pop(b);
		st_push(a, temp, sizeof(int));
		free(temp);
		if (c == 'a')
			ft_putstr_fd("pa\n", 1);
		if (c == 'b')
			ft_putstr_fd("pb\n", 1);
		return (1);
	}
	return (0);
}

int	st_rotate_ab(t_list **stack, char c)
{
	void	*elem;

	if (ft_lstsize(*stack) > 1)
	{
		elem = st_pop(stack);
		ft_lstadd_back(stack, ft_lstnew(elem));
		if (c == 'a')
			ft_putstr_fd("ra\n", 1);
		if (c == 'b')
			ft_putstr_fd("rb\n", 1);
		return (1);
	}
	return (0);
}

int	st_rrotate_ab(t_list **stack, char c)
{
	void	*elem;
	t_list	*last_a;
	t_list	*prev;

	if (ft_lstsize(*stack) > 1)
	{
		last_a = st_get_at(*stack, ft_lstsize(*stack) - 1);
		prev = st_get_at(*stack, ft_lstsize(*stack) - 2);
		elem = last_a->elem;
		st_push(stack, elem, sizeof(int));
		ft_lstdelone(last_a, free);
		prev->next = NULL;
		if (c == 'a')
			ft_putstr_fd("rra\n", 1);
		if (c == 'b')
			ft_putstr_fd("rrb\n", 1);
		return (1);
	}
	return (0);
}
