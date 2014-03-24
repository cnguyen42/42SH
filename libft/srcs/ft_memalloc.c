/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:22 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:22 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				*ft_memalloc(size_t size)
{
	void			*mem;

	mem = NULL;
	mem = (void *) malloc(size);
	if (!mem)
		return (NULL);
	return (mem);
}
