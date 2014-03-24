/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:39 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:39 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t			ft_nbrlen(int nbr)
{
	size_t		len;

	if (nbr == -2147483648)
		return (11);
	len = 1;
	if (nbr < 0)
	{
		len++;
		nbr = nbr * -1;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

size_t			ft_longlen(long nbr)
{
	size_t		len;

	len = 1;
	if (nbr < 0)
	{
		len++;
		nbr = nbr * -1;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

size_t			ft_uintlen(unsigned int nbr)
{
	size_t		len;

	len = 1;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

size_t			ft_octallen(unsigned int nbr)
{
	size_t		len;

	len = 1;
	while (nbr > 7)
	{
		nbr = nbr / 8;
		len++;
	}
	return (len);
}

size_t			ft_hexalen(unsigned long nbr)
{
	size_t		len;

	len = 1;
	while (nbr > 15)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}
