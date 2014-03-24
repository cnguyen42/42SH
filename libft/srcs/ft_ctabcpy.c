/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctabcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:36:14 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:36:14 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				**ft_ctabcpy(char **dst, char **src)
{
	size_t			index;

	index = 0;
	while (src[index])
	{
		ft_strcpy(dst[index], src[index]);
		index++;
	}
	dst[index] = NULL;
	return (dst);
}
