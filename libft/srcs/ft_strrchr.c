/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:38:21 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:38:21 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strrchr(const char *src, int value)
{
	size_t			index;
	char			*res;

	index = 0;
	res = NULL;
	while (src[index] != '\0')
	{
		if (src[index] == (char) value)
			res = (char *) &src[index];
		index++;
	}
	if ((char) value == '\0')
		return ((char *) &src[index]);
	return (res);
}
