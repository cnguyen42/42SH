/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:38:18 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:38:18 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				ft_strnequ(const char *str1, const char *str2, size_t len)
{
	size_t		index;

	index = 0;
	if (str1 == NULL || str2 == NULL)
	{
		if (str1 == str2)
			return (1);
		return (0);
	}
	while (str1[index] != '\0' && str2[index] != '\0' && index < len)
	{
		if (str1[index] != str2[index])
			return (0);
		index++;
	}
	if (str1[index] != str2[index] && index < len)
		return (0);
	return (1);
}
