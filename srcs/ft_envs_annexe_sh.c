/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envs_annexe_sh.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:39:26 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:39:26 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char		*ft_getenv(const char *name)
{
	int		i;
	char	**env;

	env = get_env();
	i = 0;
	while (env[i])
	{
		if (ft_strnequ(name, env[i], ft_strlen(name)))
		{
			if ((env[i] + ft_strlen(name))[0] == '=')
				return (ft_strdup(env[i] + 1 + ft_strlen(name)));
		}
		i++;
	}
	return (NULL);
}

int			ft_putenv(char *name, char *value)
{
	char	**env;
	char	*to_put;
	int		i;
	int		change;

	env = get_env();
	name = ft_strjoin(name, "=");
	to_put = ft_strjoin(name, value);
	change = 0;
	i = 0;
	while (env[i] && !change)
	{
		if (ft_strnequ(name, env[i], ft_strlen(name)))
		{
			env[i] = ft_strdup(to_put);
			change = 1;
		}
		i++;
	}
	if (!change)
		env = ft_ctabaddtoindex(env, setctab(to_put), i, 0);
	create_env(env);
	return (-1);
}

void		ft_printenv(void)
{
	int		i;
	char	**env;

	env = get_env();
	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

