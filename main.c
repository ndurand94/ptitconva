/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndurand <ndurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:33:24 by ndurand           #+#    #+#             */
/*   Updated: 2022/05/23 13:04:08 by ndurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	st_check(char *argv, t_list **a)
{
	int		j;
	long	elem;

	j = 0;
	while (argv[j])
	{
		if (ft_atoi2(&argv[j], &elem) == -1 || \
			st_find(*a, (void *)&elem, sizeof(int)) != -1)
		{
			ft_freelst(a, free);
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		ft_lstadd_back(a, st_newstack((void *)&elem, sizeof(int)));
		while (ft_isspace(argv[j]))
			j++;
		j += ft_strchr("+-", argv[j]) != 0;
		while (ft_isdigit(argv[j]))
			j++;
	}
	return (0);
}

static t_list	*st_parsing(int argc, char **argv)
{
	t_list	*a;
	int		i;

	a = NULL;
	i = 0;
	if (argc < 2)
		return (NULL);
	while (++i < argc)
	{
		if (st_check(argv[i], &a) == -1)
			return (NULL);
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	a = st_parsing(argc, argv);
	if (!a)
		return (0);
	st_sort(&a, &b);
	ft_freelst(&a, free);
	ft_freelst(&b, free);
	return (0);
}
