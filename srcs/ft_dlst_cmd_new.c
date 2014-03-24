/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_cmd_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:51:41 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/24 15:51:41 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_dlst_cmd			*ft_dlst_cmd_new(char c)
{
	t_dlst_cmd		*new;

	new = (t_dlst_cmd *)malloc(sizeof(t_dlst_cmd));
	new->c = c;
	new->next = (t_dlst_cmd *)malloc(sizeof(t_dlst_cmd));
	new->prev = (t_dlst_cmd *)malloc(sizeof(t_dlst_cmd));
	return (new);
}
