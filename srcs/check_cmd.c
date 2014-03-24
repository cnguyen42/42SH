/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:39:07 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:39:07 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				check_file(t_node *right)
{
	int			fd;

	if (right->flag == 3)
		exit(0);
	if (right->flag == 2)
		fd = open(right->ctab[0], O_RDONLY);
	else if (right->flag == 4)
		fd = open(right->ctab[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(right->ctab[0], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		if ((access(right->ctab[0], F_OK)) == -1)
			ft_putendl_fd(ft_strjoin(SH_NOSUCH, right->ctab[0]), 2);
		else if (right->flag == 2 && (access(right->ctab[0], R_OK)) == -1)
			ft_putendl_fd(ft_strjoin(SH_DENIED, right->ctab[0]), 2);
		else if (right->flag > 3 && (access(right->ctab[0], W_OK)) == -1)
			ft_putendl_fd(ft_strjoin(SH_DENIED, right->ctab[0]), 2);
		exit(1);
	}
	return (fd);
}

char			*check_cmd(t_sh *sh, char *cmd)
{
	char		**paths;
	char		*path;
	int			i;

	path = ft_getenv("PATH");
	if (!path)
		return (NULL);
	paths = ft_strsplit(path, ":");
	i = 0;
	while (paths[i])
	{
		path = ft_strdup(cmd);
		if (!ft_strstr(path, "/"))
			path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
		if (access(path, X_OK) >= 0)
			return (path);
		i++;
	}
	return (NULL);
	(void)sh;
}
