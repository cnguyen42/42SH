/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splittoken.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:40:48 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:40:48 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static int			isope(char *cmd, char **ope)
{
	int				j;
	int				len;

	if (!ope && !cmd)
		return (-1);
	j = 0;
	while (ope[j])
	{
		len = ft_strlen(ope[j]);
		if (ft_strnequ(ope[j], cmd, len))
			return (len);
		j++;
	}
	return (-1);
}

static int			isw(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

char				**splittoken(char **tokens, char *cmd, char **ope)
{
	int				i;
	int				j;
	int				t;
	int				ret;

	tokens = (char **)malloc(sizeof(char *) * ft_strlen(cmd) + 1);
	i = 0;
	t = 0;
	while (cmd[i])
	{
		while (cmd[i] && ((ret = isope(cmd + i, ope)) != - 1 || isw(cmd[i])))
		{
			if (ret != -1)
				tokens[t++] = ft_strsub(cmd, i, ret);
			i = (ret != -1) ? i + ret : i + 1;
		}
		j = i;
		while (cmd[j] && isope(cmd + j, ope) == -1 && !isw(cmd[j]))
			j++;
		if (j != i)
			tokens[t++] = ft_strsub(cmd, i, j - i);
		i = j;
	}
	tokens[t] = NULL;
	return (tokens);
}

