/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deci_to_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:05 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:05 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				ft_deci_to_octal(unsigned int nbr, char *octal)
{
	int				i;
	int				j;
	char			tab[] = "01234567";
	char			temp;

	j = 0;
	while (nbr > 8)
	{
		i = nbr % 8;
		octal[j] = tab[i];
		j++;
		nbr = nbr / 8;
	}
	octal[j] = tab[nbr];
	octal[j + 1] = '\0';
	i = 0;
	while (i < j)
	{
		temp = octal[j];
		octal[j] = octal[i];
		octal[i] = temp;
		i++;
		j--;
	}
}
