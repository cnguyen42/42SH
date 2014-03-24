/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:06 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:06 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int					count_neg(char *str)
{
	int				i;
	int				k;

	i = 0;
	k = 0;
	while (str[i] && ft_isdigit(str[i]) == 0)
	{
		if (str[i] == '-')
			k++;
		else if (str[i] != '-' && str[i] != '+')
			k = 0;
		i++;
	}
	return (k % 2);
}

int					ft_getnbr(char *str)
{
	int				neg;
	int				i;
	int				nbr;

	neg = count_neg(str);
	i = 0;
	while (ft_isdigit(str[i]) == 0)
		i++;
	str = str + i;
	nbr = ft_atoi(str);
	if (neg == 1)
		nbr = nbr * -1;
	return (nbr);
}
