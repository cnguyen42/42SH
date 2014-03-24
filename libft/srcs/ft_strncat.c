/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:38:15 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:38:15 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strncat(char *dst, const char *src, size_t len)
{
	size_t			index_dst;
	size_t			index_src;

	index_dst = 0;
	index_src = 0;
	while (dst[index_dst] != '\0')
		index_dst++;
	while (src[index_src] != '\0' && index_src < len)
		dst[index_dst++] = src[index_src++];
	dst[index_dst] = '\0';
	return (dst);
}
