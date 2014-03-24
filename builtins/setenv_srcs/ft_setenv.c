/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 14:34:42 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 14:34:42 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				ft_setenv(int ac, char **av)
{
	if (!ac)
		ft_printenv();
	else if (ac > 2)
	{
		ft_putendl_fd("setenv: Too many arguments.", 2);
		exit(1);
	}
	else if (ft_strchr(av[0], '='))
	{
		ft_putendl_fd("setenv: Syntax Error.", 2);
		exit(1);
	}
	else if (ac == 2)
		ft_putenv(av[0], av[1]);
	else
		ft_putenv(av[0], "");
	return (0);
}
