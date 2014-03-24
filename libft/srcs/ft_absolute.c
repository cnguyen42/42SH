/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:36:08 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:36:08 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				ft_absolute(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}