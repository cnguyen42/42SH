/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctablen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:03 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:03 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t				ft_ctablen(char **ctab)
{
	size_t			index;

	index = 0;
	if (ctab)
	{
		while (ctab[index])
			index++;
	}
	return (index);
}
