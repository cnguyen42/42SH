/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:32 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:32 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				*ft_memcpy(void *dst, const void *src, size_t len)
{
	char			*p_dst;
	char			*p_src;
	size_t			k;

	if (!dst || !src || !len)
		return (dst);
	p_dst = (char*) dst;
	p_src = (char*) src;
	k = 0;
	while (k < len)
	{
		p_dst[k] = p_src[k];
		k++;
	}
	return (dst);
}
