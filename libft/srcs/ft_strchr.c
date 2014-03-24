/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:53 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:53 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strchr(const char *src, int value)
{
	size_t			index;

	if (!src)
		return (NULL);
	index = 0;
	while (src[index] != '\0')
	{
		if (src[index] == (char) value)
			return ((char *) &src[index]);
		index++;
	}
	if ((char) value == '\0')
		return ((char *) &src[index]);
	return (NULL);
}
