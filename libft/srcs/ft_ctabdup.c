/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctabdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:36:54 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:36:54 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		**ft_ctabdup(char **ctab)
{
	char	**dup;
	int		i;

	if (!ctab)
		return (NULL);
	dup = (char**)malloc(sizeof(char *) * (ft_ctablen(ctab) + 1));
	i = 0;
	while (ctab[i])
	{
		dup[i] = ctab[i];
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
