/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_histo_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:48:27 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/24 15:48:27 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_dlst_histo		*ft_dlst_histo_new(t_cmd *cmd)
{
	t_dlst_histo	*new;

	new = (t_dlst_histo *)malloc(sizeof(t_dlst_histo));
	new->cmd = cmd;
	new->next = (t_dlst_histo *)malloc(sizeof(t_dlst_histo));
	new->prev = (t_dlst_histo *)malloc(sizeof(t_dlst_histo));
	return (new);
}
