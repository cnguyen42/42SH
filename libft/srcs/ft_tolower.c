/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:38:47 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:38:47 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_tolower(int value)
{
	if (value < 0101 || value > 0132)
		return (value);
	return (value - 0101 + 0141);
}
