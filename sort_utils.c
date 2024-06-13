/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndurand <ndurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:04:04 by ndurand           #+#    #+#             */
/*   Updated: 2022/05/20 16:53:27 by ndurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	st_is_ordered(t_list *stack)
{
	void	*prev;

	prev = NULL;
	if (!stack)
		return (0);
	while (stack)
	{
		if (prev && *(int *)prev > *(int *)stack->elem)
			return (0);
		prev = stack->elem;
		stack = stack->next;
	}
	return (1);
}

int	st_top(t_list **stack, void *elem, char c)
{
	int		pos;
	void	*aux;

	aux = malloc(sizeof(int));
	if (!aux)
		return (0);
	ft_memcpy(aux, elem, sizeof(int));
	pos = st_find(*stack, elem, sizeof(int));
	if (*(int *)stack[0]->elem != *(int *)aux && pos != -1)
	{
		while (ft_memcmp(aux, stack[0]->elem, sizeof(int)))
		{
			if (pos > (ft_lstsize(*stack) - 1) / 2)
				st_rrotate_ab(stack, c);
			else
				st_rotate_ab(stack, c);
		}
	}
	free(aux);
	return (0);
}

void	st_index(t_list **stack)
{
	t_list	*aux;
	int		len;
	int		i;
	int		elem;

	i = 0;
	elem = 0;
	aux = NULL;
	len = ft_lstsize(*stack);
	while (i++ < len)
		ft_lstadd_front(&aux, st_newstack((void *)&elem, sizeof(int)));
	i = 0;
	elem = *(int *)st_max(*stack)->elem + 1;
	while (i < len)
	{
		st_replace_at(&aux, st_find(*stack, st_min(*stack)->elem, \
			sizeof(int)), (void *)&i, sizeof(int));
		st_replace_at(stack, st_find(*stack, st_min(*stack)->elem, \
			sizeof(int)), (void *)&elem, sizeof(int));
		i++;
		elem++;
	}
	ft_freelst(stack, free);
	*stack = aux;
}

int	st_get_sorted(t_list *a, t_list *b, char c)
{
	int	len;
	int	count;

	count = 0;
	len = 0;
	while (c == 'a' && a)
	{
		if (*(int *)a->elem == len)
			count++;
		else
			count = 0;
		len++;
		a = a->next;
	}
	len = ft_lstsize(b) - 1;
	while (c == 'b' && b)
	{
		if (*(int *)b->elem == len)
			count++;
		else
			count = 0;
		len--;
		b = b->next;
	}
	return (count);
}
