/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:23 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:23 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;
	size_t			k;

	p_dst = (unsigned char*) dst;
	p_src = (unsigned char*) src;
	k = 0;
	while (k < len)
	{
		if ((*p_dst++ = *p_src++) == c)
			return (p_dst);
		k++;
	}
	return (NULL);
}
