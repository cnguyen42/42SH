/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:29 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:29 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int					ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char	*pS1;
	unsigned char	*pS2;
	size_t			k;

	pS1 = (unsigned char *) s1;
	pS2 = (unsigned char *) s2;
	k = 0;
	while (k < len)
	{
		if (pS1[k] != pS2[k])
			return (pS1[k] - pS2[k]);
		k++;
	}
	return (0);
}
