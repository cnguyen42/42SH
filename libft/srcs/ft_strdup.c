/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:38:05 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:38:05 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strdup(const char *src)
{
	char			*dst;

	dst = NULL;
	if (src != NULL)
	{
		dst = (char *) malloc(sizeof(*dst) * (ft_strlen(src) + 1));
		if (dst != NULL)
			ft_strcpy(dst, src);
	}
	return (dst);
}
