/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:38:13 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:38:13 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t			ft_strlen(const char *str)
{
	size_t		index;

	index = 0;
	if (str)
	{
		while (str[index])
			index++;
	}
	return (index);
}
