/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:38:10 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:38:10 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_strjoin(const char *str1, const char *str2)
{
	char		*new_str;
	size_t		index1;
	size_t		index2;

	new_str = NULL;
	if (str1 && str2)
	{
		new_str = (char *) malloc(sizeof(*new_str) *\
				(ft_strlen(str1) + ft_strlen(str2) + 1));
		index1 = 0;
		while (str1[index1] != '\0')
		{
			new_str[index1] = str1[index1];
			index1++;
		}
		index2 = 0;
		while (str2[index2] != '\0')
		{
			new_str[index1] = str2[index2];
			index1++;
			index2++;
		}
		new_str[index1] = '\0';
	}
	return (new_str);
}
