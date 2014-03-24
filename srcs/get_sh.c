/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:48:07 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/24 15:48:07 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_sh				*get_sh(int *stop)
{
	t_sh			*sh;

	sh = (t_sh *)malloc(sizeof(t_sh));
	sh->stop = stop;
	sh->histo = (t_dlst_histo **)malloc(sizeof(t_dlst_histo *));
	*(sh->histo) = ft_dlst_histo_new(0);
	sh->histo_size = 0;
	sh->histo_pos = 0;
	sh->pid = ft_itoa(getpid());
	return (sh);
}

