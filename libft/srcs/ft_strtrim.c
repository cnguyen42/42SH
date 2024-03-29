/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:38:46 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:38:46 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strtrim(const char *str)
{
	int				before;
	int				after;
	size_t			i;
	char			*new_str;

	if (str == NULL)
		return (NULL);
	before = 0;
	while (str[before] == ' ' || str[before] == '\n' || str[before] == '\t')
		before++;
	i = ft_strlen(str);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\0')
		i--;
	after = ft_strlen(str) - i - 1;
	new_str = ft_strnew(ft_strlen(str) - after - before + 1);
	new_str = ft_strsub(str, before, ft_strlen(str) - after - before);
	if (!new_str)
	{
		new_str = ft_strnew(1);
		new_str[0] = '\0';
	}
	return (new_str);
}
