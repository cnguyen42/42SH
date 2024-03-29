/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:09 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:37:09 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				ft_isalnum(int value)
{
	if (ft_isdigit(value) == 1 || ft_isalpha(value) == 1)
		return (1);
	return (0);
}
