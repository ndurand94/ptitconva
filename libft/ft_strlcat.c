/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndurand <ndurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:24:54 by ndurand           #+#    #+#             */
/*   Updated: 2021/11/29 19:24:54 by ndurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;	
	size_t	len_total;

	i = 0;
	len_dest = ft_strlen(dst);
	len_total = ft_strlen(src);
	if (size <= len_dest)
		return (len_total + size);
	else
		len_total += len_dest;
	while (src[i] && len_dest < size - 1)
	{
		dst[len_dest] = src[i];
		i++;
		len_dest++;
	}
	dst[len_dest] = '\0';
	return (len_total);
}
