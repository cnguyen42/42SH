/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 14:30:01 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:20:17 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int					ft_echo(int ac, char **av)
{
	int				i;
	int				n;

	n = 0;
	i = 0;
	if (ft_strequ(av[0], "-n"))
	{
		n++;
		i++;
	}
	while (i < ac)
	{
		ft_putstr(av[i]);
		if (i != ac - 1)
			ft_putchar(' ');
		i++;
	}
	if (!n)
		ft_putchar('\n');
	return (EXIT_SUCCESS);
}
