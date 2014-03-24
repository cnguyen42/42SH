/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:20:52 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:20:52 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				ft_unsetenv(int ac, char **av, int i, int j)
{
	char		*tmp;
	char		**env;

	env = get_env();
	if (!ac)
	{
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
		return (EXIT_FAILURE);
	}
	while (i < ac)
	{
		j = 0;
		while (env[j])
		{
			tmp = ft_strjoin(av[i], "=");
			if (ft_strnequ(tmp, env[j], ft_strlen(tmp)))
				env = ft_ctabdel(env, j);
			j++;
		}
		i++;
	}
	create_env(env);
	return (EXIT_SUCCESS);
}
