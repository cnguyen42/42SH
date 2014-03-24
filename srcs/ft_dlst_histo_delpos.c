/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_histo_delpos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:48:23 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/24 15:48:23 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void				ft_dlst_histo_delpos(t_sh *sh, int pos)
{
	t_dlst_histo	*current;
	t_dlst_histo	*cur_prev;
	t_dlst_histo	*cur_next;
	int				i;

	current = *(sh->histo);
	i = 0;
	while (i++ < pos)
		current = current->next;
	cur_prev = current->prev;
	cur_next = current->next;
	cur_prev->next = cur_next;
	cur_next->prev = cur_prev;
	if (!pos)
		*(sh->histo) = cur_next;
	sh->histo_size = sh->histo_size - 1;
}
