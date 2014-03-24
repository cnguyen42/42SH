/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_sh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 14:29:57 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 14:29:57 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int					ft_cd(int ac, char **av)
{
	char			*path;

	path = NULL;
	if (ac == 0)
		path = get_path("HOME");
	else if (ac == 1)
	{
		if (ft_strequ(av[0], "-"))
			path = get_path("OLDPWD");
		else
			path = av[0];
	}
	else if (ac == 2)
		cd_replace(ac, av);
	else if (ac > 2)
		ft_putendl_fd(CD_TOMANY, 2);
	if (path)
		cd_env_change(path);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

char				*get_path(char *name)
{
	char			*path;

	path = ft_getenv(name);
	if (path)
		return (path);
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(name, 2);
	ft_putendl_fd(" not set", 2);
	exit(EXIT_FAILURE);
}

char				*cd_replace(int ac, char **av)
{
	int				i;
	char			*res;

	if ((i = ft_strfstr(ft_getenv("PWD"), av[ac - 2])))
	{
		res = ft_strdup(ft_strsub(ft_getenv("PWD"), 0, i));
		res = ft_strjoin(res, av[ac - 1]);
		res = ft_strjoin(res, ft_strsub(ft_getenv("PWD"),
	i + ft_strlen(av[ac - 2]),
	ft_strlen(ft_getenv("PWD")) - i - ft_strlen(av[ac - 2])));
		if (access(res, F_OK))
			ft_putendl_fd(ft_strjoin(CD_NOSUCH, res), 2);
		else
			return (res);
		return (NULL);
	}
	ft_putendl(ft_strjoin(CD_NOSTR, av[ac - 2]));
	return (NULL);
}

void				cd_env_change(char *newpwd)
{
	char			*save;

	save = ft_strdup(newpwd);
	newpwd = parse_pwd(newpwd);
	if (access(newpwd, X_OK) == -1)
	{
		ft_putendl_fd(ft_strjoin(CD_NOSUCH, save), 2);
		exit(EXIT_FAILURE);
	}
	ft_putenv("OLDPWD", ft_getenv("PWD"));
	ft_putenv("PWD", newpwd);
}

char				*parse_pwd(char *path)
{
	char			*ret;
	char			**ctab;
	int				i;

	if (path[0] == '/')
		return (path);
	if (path[0] == '~' && path[1] == '/')
		path = ft_strjoin(ft_getenv("HOME"), path + 1);
	ret = ft_getenv("PWD");
	ctab = ft_strsplit(path, "/");
	i = 0;
	while (ctab[i])
	{
		if (ft_strequ(ctab[i], ".."))
			ret[ft_strrfound(ret, '/')] = 0;
		else if (!ft_strequ(ctab[i], "."))
			ret = ft_strjoin(ret, ft_strjoin("/", ctab[i]));
		i++;
	}
	return (ret);
}
