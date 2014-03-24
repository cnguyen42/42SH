/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:39:34 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:39:34 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			printprompt2(t_usent **ptr_us);
void			printprompt3(t_usent **ptr_us);

void			printprompt(t_usent **us)
{
	static t_usent		**ptr_us = NULL;
	char				blue[] = "\x1B[1;34m";
	char				*pwd;
	char				*home;

	if (!ptr_us)
	{
		ptr_us = (t_usent **)malloc(sizeof(t_usent *));
		*ptr_us = NULL;
	}
	if (us)
		*ptr_us = *us;
	(*ptr_us)->prompt_size = 0;
	pwd = ft_getenv("PWD");
	chdir(pwd);
	home = ft_getenv("HOME");
	ft_putstr_fd(blue, 2);
	printprompt2(ptr_us);
	(*ptr_us)->curs_col = 	(*ptr_us)->prompt_size;
}

void			printprompt2(t_usent **ptr_us)
{
	char				yellow[] = "\x1B[4;33m";

	if (ft_getenv("USER"))
	{
		ft_putstr_fd(ft_getenv("USER"), 2);
		(*ptr_us)->prompt_size += ft_strlen(ft_getenv("USER")) + 1;
	}
	else
	{
		ft_putstr_fd("42", 2);
		(*ptr_us)->prompt_size += 2 + 1;
	}
	ft_putchar_fd(' ', 2);
	ft_putstr_fd(yellow, 2);
	printprompt3(ptr_us);
}

void			printprompt3(t_usent **ptr_us)
{
	char				white[] = "\x1B[0m";
	char				*pwd;
	char				*home;

	pwd = ft_getenv("PWD");
	home = ft_getenv("HOME");
	if (ft_strnequ(pwd, home, ft_strlen(home)))
	{
		ft_putstr_fd("~", 2);
		ft_putstr_fd(pwd + ft_strlen(home), 2);
		(*ptr_us)->prompt_size += 1 + ft_strlen(pwd) - ft_strlen(home);
	}
	else
	{
		ft_putstr_fd(pwd, 2);
		(*ptr_us)->prompt_size += ft_strlen(pwd);
	}
	ft_putstr_fd(white, 2);
	ft_putstr_fd(" > ", 2);
	(*ptr_us)->prompt_size += 3;
}
