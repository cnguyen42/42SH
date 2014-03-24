/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:38:14 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:38:14 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	index;

	new_str = NULL;
	if (str && f)
	{
		new_str = (char *) malloc(sizeof(*new_str) * (ft_strlen(str) + 1));
		index = 0;
		while (str[index] != '\0')
		{
			new_str[index] = f(index, str[index]);
			index++;
		}
		new_str[index] = '\0';
	}
	return (new_str);
}
