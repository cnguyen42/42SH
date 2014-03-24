/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:10 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:10 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_isalpha(int value)
{
	if (value < 0101 || value > 0132)
	{
		if (value < 0141 || value > 0172)
			return (0);
	}
	return (1);
}
