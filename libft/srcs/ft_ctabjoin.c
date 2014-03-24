/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctabjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:00 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:00 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			**ft_ctabjoin(char **ctab1, char **ctab2)
{
	char		**new_ctab;
	size_t		index1;
	size_t		index2;

	new_ctab = NULL;
	if (ctab1 && ctab2)
	{
		new_ctab = (char **) malloc(sizeof(char *) *
				(ft_ctablen(ctab1) + ft_ctablen(ctab2) + 1));
		index1 = 0;
		while (ctab1[index1])
		{
			new_ctab[index1] = ctab1[index1];
			index1++;
		}
		index2 = 0;
		while (ctab2[index2])
		{
			new_ctab[index1] = ctab2[index2];
			index1++;
			index2++;
		}
		new_ctab[index1] = NULL;
	}
	return (new_ctab);
}
