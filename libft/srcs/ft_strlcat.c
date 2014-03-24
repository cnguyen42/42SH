/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:38:12 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:38:12 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t			ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t		dst_len;
	size_t		res;
	size_t		i;
	size_t		j;

	dst_len = ft_strlen(dst);
	res = dst_len + ft_strlen(src);
	i = 0;
	j = 0;
	if (len <= dst_len)
		res = res - (dst_len - len);
	else
	{
		len = len - (dst_len + 1);
		while (dst[i] != '\0')
			i++;
		while (src[j] != '\0' && j < len)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (res);
}
