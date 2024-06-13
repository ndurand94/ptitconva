/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndurand <ndurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:28:30 by ndurand           #+#    #+#             */
/*   Updated: 2021/11/29 19:28:30 by ndurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str1;

	str1 = (char *)s1;
	start = 0;
	i = 0;
	while (s1[start] && ft_cset(s1[start], set))
		start++;
	end = ft_strlen(str1);
	while (end > start && ft_cset(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (0);
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
