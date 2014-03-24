/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:38:08 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:38:08 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			ft_striter(char *str, void (*f)(char *))
{
	size_t		index;

	if (str && f)
	{
		index = 0;
		while (str[index] != '\0')
		{
			(*f)(str + index);
			index++;
		}
	}
}
