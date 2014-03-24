/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_miniprompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:39:33 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:39:33 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void				print_miniprompt(t_cmd *cmd)
{
	int				i;
	char			*strings[6] = STRINGS;
	int				flag;

	flag = 0;
	i = 5;
	while (i >= 0)
	{
		if (cmd->state_bool[i])
		{
			ft_putstr_fd(strings[i], 2);
			flag = 1;
		}
		i--;
	}
	if (flag)
		ft_putstr_fd("> ", 2);
}
