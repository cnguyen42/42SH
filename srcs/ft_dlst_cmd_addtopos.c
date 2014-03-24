/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_cmd_addtopos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:47:50 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/24 15:47:50 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static void			modif(t_dlst_cmd *current, t_dlst_cmd *new,
							t_dlst_cmd *current_next)
{
	current->next = new;
	new->prev = current;
	new->next = current_next;
	current_next->prev = new;
}

void				ft_dlst_cmd_addtopos(t_cmd *cmd, t_dlst_cmd *new, int pos)
{
	t_dlst_cmd		*current;
	t_dlst_cmd		*current_next;
	int				i;

	current = *(cmd->adlst);
	i = 1;
	while (i++ < pos)
		current = current->next;
	current_next = current->next;
	if (cmd->size == 0)
	{
		new->next = new;
		new->prev = new;
		*(cmd->adlst) = new;
	}
	else if (pos)
		modif(current, new, current_next);
	else
	{
		new->next = current;
		current->prev = new;
		*(cmd->adlst) = new;
	}
	cmd->size++;
}
