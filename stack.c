/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndurand <ndurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:18:51 by ndurand           #+#    #+#             */
/*   Updated: 2022/05/23 13:06:09 by ndurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*st_pop(t_list **stack)
{
	void	*out;
	t_list	*head;

	out = NULL;
	if (!stack || !stack[0])
		return (NULL);
	head = *stack;
	if (head->next)
	{
		*stack = head->next;
		out = head->elem;
		free(head);
		return (out);
	}
	out = head->elem;
	free(head);
	*stack = NULL;
	return (out);
}

int	st_push(t_list **stack, void *newelem, size_t size)
{
	t_list	*new;

	new = st_newstack(newelem, size);
	if (!new)
		return (0);
	ft_lstadd_front(stack, new);
	return (1);
}

t_list	*st_newstack(void *newelem, size_t size)
{
	t_list	*new;
	void	*elem;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	elem = malloc(size);
	if (!elem)
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(elem, newelem, size);
	new->elem = elem;
	new->next = NULL;
	return (new);
}

void	st_freestack(t_list **stack)
{
	t_list	*temp;

	temp = NULL;
	if (*stack)
	{
		while (*stack)
		{
			temp = *stack;
			stack[0] = stack[0]->next;
			free(temp->elem);
			free(temp);
			temp = NULL;
		}
	}
	*stack = NULL;
}
