/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndurand <ndurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:01:39 by ndurand           #+#    #+#             */
/*   Updated: 2021/11/29 19:01:39 by ndurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	totale;
	char	*memory;
	size_t	i;

	i = 0;
	totale = count * size;
	memory = malloc(totale);
	if (!memory)
		return (0);
	while (i < totale)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}
