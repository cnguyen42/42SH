/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 16:29:28 by jponcele          #+#    #+#             */
/*   Updated: 2014/02/18 10:35:24 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_cmd					*ft_cmd_dup(t_cmd *cmd)
{
	t_cmd				*new;
	t_dlst_cmd			*current;
	int					i;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	new->size = 0;
	new->cursor = cmd->cursor;
	new->index = cmd->index;
	new->state = cmd->state;
	new->state_bool = cmd->state_bool;
	new->adlst = (t_dlst_cmd **)malloc(sizeof(t_dlst_cmd *));
	*(new->adlst) = ft_dlst_cmd_new(0);
	current = *(cmd->adlst);
	i = 0;
	while (i < cmd->size)
	{
		ft_dlst_cmd_addtopos(new, ft_dlst_cmd_new(current->c), new->size);
		current = current->next;
		i++;
	}
	return (new);
}
