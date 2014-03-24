/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_histo_addtopos.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:51:34 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/24 15:51:34 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static void			modif(t_dlst_histo *current, t_dlst_histo *new,
							t_dlst_histo *current_next)
{
	current->next = new;
	new->prev = current;
	new->next = current_next;
	current_next->prev = new;
}

void				ft_dlst_histo_addtopos(t_sh *sh, t_dlst_histo *new, int pos)
{
	t_dlst_histo	*current;
	t_dlst_histo	*current_next;
	int				i;

	current = *(sh->histo);
	i = 1;
	while (i++ < pos)
		current = current->next;
	current_next = current->next;
	if (sh->histo_size == 0)
	{
		new->next = new;
		new->prev = new;
		*(sh->histo) = new;
	}
	else if (pos)
		modif(current, new, current_next);
	else
	{
		new->next = current;
		current->prev = new;
		*(sh->histo) = new;
	}
	sh->histo_size = sh->histo_size + 1;
}
