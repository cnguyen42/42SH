/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfound.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:38:07 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:38:07 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int					ft_strfound(const char *src, int value)
{
	int				index;

	if (!src)
		return (0);
	index = 0;
	while (src[index] != '\0')
	{
		if (src[index] == (char) value)
			return (index);
		index++;
	}
	if ((char) value == '\0')
		return (index);
	return (0);
}
