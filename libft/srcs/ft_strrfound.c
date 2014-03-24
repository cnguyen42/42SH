/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrfound.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:38:22 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:38:37 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int					ft_strrfound(const char *src, int value)
{
	size_t			index;
	int				res;

	index = 0;
	res = -1;
	while (src[index] != '\0')
	{
		if (src[index] == (char) value)
			res = index;
		index++;
	}
	return (res);
}
