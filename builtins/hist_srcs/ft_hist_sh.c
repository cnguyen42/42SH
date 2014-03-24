/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hist_sh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 14:30:09 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:20:25 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int					ft_history(int ac, char **av)
{
	t_dlst_histo	*current;
	int				i;

	if (!ac)
	{
		ft_putendl_fd("history: too many arguments", 2);
		exit (1);
	}
	current = *(sh->histo);
	i = 0;
	while (i < sh->histo_size)
	{
		ft_putendl_fd(ft_dlst_cmd_tostr(current->cmd), 2);
		current = current->next;
		i++;
	}
	return (0);
}
