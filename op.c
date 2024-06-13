/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndurand <ndurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:11:38 by ndurand           #+#    #+#             */
/*   Updated: 2022/05/20 16:51:46 by ndurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi2(const char *nptr, long *nbr)
{
	int		sign;

	sign = 1;
	*nbr = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -sign;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	if (!ft_isdigit(*nptr))
		return (-1);
	while (ft_isdigit(*nptr))
	{
		*nbr = 10 * *nbr + (*nptr - '0');
		if (*nbr > 2147483647 && sign == 1)
			return (-1);
		if (*nbr > 2147483648 && sign == -1)
			return (-1);
		nptr++;
	}
	if (*nptr && !ft_isspace(*nptr))
		return (-1);
	*nbr *= sign;
	return (0);
}

int	st_swap_ss(t_list **a, t_list **b)
{
	st_swap_ab(a, 0);
	st_swap_ab(b, 0);
	ft_putstr_fd("ss\n", 1);
	return (1);
}

int	st_rotate_rr(t_list **a, t_list **b)
{
	if (!st_rotate_ab(a, 0))
		return (0);
	if (!st_rotate_ab(b, 0))
		return (0);
	ft_putstr_fd("rr\n", 1);
	return (1);
}

int	st_rrotate_rrr(t_list **a, t_list **b)
{
	if (!st_rrotate_ab(a, 0))
		return (0);
	if (!st_rrotate_ab(b, 0))
		return (0);
	ft_putstr_fd("rrr\n", 1);
	return (1);
}
