/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:08 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:08 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char		fill_option(char c, char **tab, char *valid_opt)
{
	size_t			i;

	i = 0;
	while (i < ft_strlen(valid_opt))
	{
		if (valid_opt[i] == c)
		{
			*tab[ft_strlen(*tab)] = c;
			*tab[ft_strlen(*tab)] = '\0';
			return ('1');
		}
		i++;
	}
	return ('0');
}

static int		print_illegal(char *cmd, char option, char *error)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": illegal option -- ", 2);
	ft_putchar_fd(option, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd(error, 2);
	return (-1);
}

int				ft_getopt(char **cmd, char **tab, char *valid_opt, char *error)
{
	size_t			i;
	unsigned int	j;
	char			option;

	i = 1;
	option = '1';
	*tab = ft_strnew(1);
	while (i < ft_ctablen(cmd) && option == '1')
	{
		if (ft_strequ(cmd[i], "--"))
			return (i + 1);
		j = 1;
		if (cmd[i][0] != '-' || cmd[i][1] == '\0')
			option = '0';
		while (option == '1' && cmd[i][j] != '\0')
		{
			if (fill_option(cmd[i][j], tab, valid_opt) == '0')
				return (print_illegal(cmd[0], cmd[i][j], error));
			j++;
		}
		i++;
	}
	return ((option == '0' || i == 1) ? i - 1 : i);
}
