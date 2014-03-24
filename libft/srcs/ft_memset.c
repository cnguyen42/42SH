/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:38 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:38 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				*ft_memset(void *to_set, int value, size_t len)
{
	unsigned char	*p_to_set;
	size_t			k;

	p_to_set = (unsigned char*) to_set;
	k = 0;
	while (k < len)
		p_to_set[k++] = (unsigned char) value;
	return (to_set);
}
