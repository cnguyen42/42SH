/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:38:17 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:38:17 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		index;

	index = 0;
	while (index < len)
	{
		dst[index] = src[index];
		index++;
	}
	if (len != index)
		dst[index] = '\0';
	return (dst);
}
