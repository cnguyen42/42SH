/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:19 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:19 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list				*ft_lstnew(const void *content, size_t content_size)
{
	t_list			*new_link;
	void			*tmp;

	new_link = (t_list *) malloc(sizeof(*new_link));
	if (!new_link)
		return (NULL);
	if (content == NULL)
	{
		new_link->content = NULL;
		new_link->content_size = 0;
	}
	else
	{
		tmp = ft_memalloc(content_size);
		if (!tmp)
			return (NULL);
		new_link->content = ft_memcpy(tmp, content, content_size);
		new_link->content_size = content_size;
	}
	new_link->next = NULL;
	return (new_link);
}
