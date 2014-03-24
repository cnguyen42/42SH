/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:38:07 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:38:07 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int					ft_strfstr(const char *str1, const char *str2)
{
	size_t			i;
	size_t			j;
	size_t			i_tmp;

	if (!str2 || ft_strlen(str2) == 0)
		return (0);
	i = 0;
	j = 0;
	while (str1[i] != '\0')
	{
		i_tmp = i;
		while (str1[i] == str2[j] && str1[i] != '\0' && str2[j] != '\0')
		{
			i++;
			j++;
		}
		if (str2[j] == '\0')
			return (i_tmp);
		i = i_tmp + 1;
		j = 0;
	}
	return (0);
}
