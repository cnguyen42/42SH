/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctabsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:04 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:04 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			**ft_ctabsub(char **ctab, int start, size_t len)
{
	char		**new_ctab;
	size_t		new_index;

	new_ctab = NULL;
	if (ctab)
	{
		if (len > (ft_ctablen(ctab) + 1 - start))
			return (ft_ctabdup(ctab));
		new_index = 0;
		new_ctab = (char **)malloc(sizeof(char *) * (len + 1));
		if (new_ctab)
		{
			while (new_index < len)
			{
				new_ctab[new_index] = ft_strdup(ctab[start++]);
				new_index++;
			}
		}
		new_ctab[new_index] = NULL;
	}
	return (new_ctab);
}
