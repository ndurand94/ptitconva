/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndurand <ndurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:21:35 by ndurand           #+#    #+#             */
/*   Updated: 2022/05/20 16:53:27 by ndurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	st_find(t_list *stack, void *elem, size_t size)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (!ft_memcmp(stack->elem, elem, size))
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

t_list	*st_min(t_list *stack)
{
	t_list	*min;

	min = NULL;
	while (stack)
	{
		if (!min || *(int *)min->elem > *(int *)stack->elem)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_list	*st_max(t_list *stack)
{
	t_list	*max;

	max = NULL;
	while (stack)
	{
		if (!max || *(int *)max->elem < *(int *)stack->elem)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_list	*st_get_at(t_list *stack, int index)
{
	int		i;

	i = 0;
	while (stack)
	{
		if (i == index)
			return (stack);
		i++;
		stack = stack->next;
	}
	return (NULL);
}

void	st_replace_at(t_list **stack, int index, void *nw, int size)
{
	int		i;
	t_list	*start;

	i = 0;
	start = *stack;
	while (start)
	{
		if (i == index)
		{
			free(start->elem);
			start->elem = NULL;
			start->elem = malloc(size);
			ft_memcpy(start->elem, nw, size);
			break ;
		}
		i++;
		start = start->next;
	}
}
