/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:16 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:16 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				ft_lstaddend(t_list **alst, t_list *new)
{
	t_list			*save;
	t_list			*current;

	save = *alst;
	current = *alst;
	while (current->next)
		current = current->next;
	current->next = new;
	*alst = save;
}
