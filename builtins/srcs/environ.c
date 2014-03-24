/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:20:48 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:20:48 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void				create_env(char **env)
{
	int				fd;
	char			*len;
	int				i;

	if (!env[0])
		env = default_env();
	fd = open(ENV_FILE, O_RDWR | O_CREAT | O_TRUNC, 0644);
	len = ft_itoa(ft_ctablen(env));
	write(fd, len, ft_strlen(len));
	write(fd, "\n", 1);
	i = 0;
	while (env[i])
	{
		write(fd, env[i], ft_strlen(env[i]));
		write(fd, "\n", 1);
		i++;
	}
	close(fd);
}

char				**default_env(void)
{
	char			**env;

	env = (char **)malloc(sizeof(char *) * 4);
	env[0] = ft_strjoin(PA1, PA2);
	env[1] = TERM;
	env[2] = ft_strjoin("PWD=", getcwd(NULL, 2048));
	env[3] = NULL;
	return (env);
}

char				**get_env(void)
{
	int				fd;
	char			*line;
	int				len;
	char			**env;
	int				i;

	fd = open(ENV_FILE, O_RDWR);
	get_next_line(fd, &line);
	len = ft_atoi(line);
	env = (char **)malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (i < len)
	{
		get_next_line(fd, &line);
		env[i] = ft_strdup(line);
		i++;
	}
	env[i] = NULL;
	close(fd);
	return (env);
}

char				**add_builtin_pid(char **env)
{
	char			*paths;

	paths = ft_getenv("PATH");
	paths = ft_strjoin(ft_strjoin(ft_getenv("PWD"), "/builtins:"), paths);
	ft_putenv("PATH", paths);
	ft_putenv("PID", ft_itoa(getpid()));
	return (env);
}
