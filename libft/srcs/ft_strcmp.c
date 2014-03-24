/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:55 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:55 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int					ft_strcmp(const char *str1, const char *str2)
{
	size_t			k;

	k = 0;
	while (str1[k] != '\0' && str2[k] != '\0' && str1[k] == str2[k])
		k++;
	if (str1[k] > str2[k])
		return (1);
	else if (str1[k] == str2[k])
		return (0);
	return (-1);
}
