/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:47 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:47 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

void			ft_putlong(long nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		ft_putlong(nbr / 10);
		ft_putlong(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

void			ft_putuint(unsigned int nbr)
{
	if (nbr > 9)
	{
		ft_putlong(nbr / 10);
		ft_putlong(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}
