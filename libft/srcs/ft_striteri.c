/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:38:09 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:38:09 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void				ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	if (str && f)
	{
		index = 0;
		while (str[0] != '\0')
		{
			(*f)(index, str);
			str++;
			index++;
		}
	}
}
