/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:40:57 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:40:57 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				ft_semicolon(t_sh *sh, t_node *cur, t_node *left, t_node *right)
{
	int			left_ret;
	int			right_ret;
	int			ret;

	left_ret = ft_seminode(sh, left) / 256;
	right_ret = ft_seminode(sh, right) / 256;
	if (cur->dad)
	{
		if (right->flag == 6)
			exit(left_ret);
		exit(right_ret);
	}
	ret = (right->flag == 6) ? left_ret : right_ret;
	ft_putenv("?", ft_itoa(ret));
	return (ret);
}

int				ft_seminode(t_sh *sh, t_node *node)
{
	pid_t		son;
	int			ret;

	ret = 0;
	son = fork();
	if (son > 0)
		waitpid(son, &ret, 0);
	if (!son)
		exec_node(sh, node);
	return (ret);
}

int				ft_pipe(t_sh *sh, t_node *cur, t_node *left, t_node *right)
{
	int			pipe_fd[2];
	pid_t		son;

	pipe(pipe_fd);
	if (!left->len)
	{
		ft_putendl_fd(ft_strjoin(SH_PARSE, "`|'"), 2);
		exit(EXIT_FAILURE);
	}
	son = fork();
	if (!son)
	{
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);
		exit(exec_node(sh, left));
	}
	if (son > 0)
	{
		dup2(pipe_fd[0], 0);
		close(pipe_fd[1]);
		ft_sleep(10);
		exit(exec_node(sh, right));
	}
	return (EXIT_SUCCESS);
	(void)cur;
}

int				ft_chevron(t_sh *sh, t_node *cur, t_node *left, t_node *right)
{
	pid_t		son;
	int			fd;
	int			ret;

	if (!right->len)
		ft_putendl_fd(ft_strjoin(SH_PARSE, "`\\n'"), 2);
	fd = check_file(right);
	son = fork();
	if (!son)
	{
		if (right->flag > 3)
			dup2(fd, 1);
		else if (right->flag == 2)
			dup2(fd, 0);
		exec_node(sh, left);
	}
	if (son > 0)
	{
		wait(&ret);
		close(fd);
		exit(ret);
	}
	return (EXIT_SUCCESS);
	(void)cur;
}

int				ft_cmd(t_sh *sh, t_node *cur, t_node *left, t_node *right)
{
	char		*cmd;
	char		*test[2] = {sh->pid, NULL};

	cmd = NULL;
	if (cur->flag == 6)
		exit(EXIT_SUCCESS);
	if (!(cmd = check_cmd(sh, cur->ctab[0])))
	{
		ft_putendl_fd(ft_strjoin(SH_NOTFOUND, cur->ctab[0]), 2);
		exit(EXIT_FAILURE);
	}
	set_signal();
	ft_putenv("PID_EXECV", ft_itoa(getpid()));
	check_glob(cur->ctab);
	execve(cmd, cur->ctab, test);
	return (EXIT_FAILURE);
	(void)left;
	(void)right;
}
