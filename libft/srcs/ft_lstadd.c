/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:14 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:14 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				ft_lstadd(t_list **alst, t_list *new_link)
{
	t_list			**save;

	if (!alst)
		*alst = new_link;
	save = alst;
	new_link->next = *save;
	alst = &new_link;
}
