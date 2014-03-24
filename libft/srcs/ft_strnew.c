/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:38:19 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:38:19 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_strnew(size_t size)
{
	char		*str;
	size_t		index;

	if (!size)
		return (NULL);
	index = 0;
	str = (char *) malloc(sizeof(*str) * (size + 1));
	if (str != NULL)
	{
		while (index < size)
		{
			str[index] = '\0';
			index++;
		}
		str[index] = '\0';
	}
	return (str);
}
