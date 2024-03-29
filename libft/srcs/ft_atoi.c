/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:36:09 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:36:09 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int			get_max_range(const char *str, size_t index)
{
	size_t			res;
	size_t			tmp;

	tmp = index;
	while (ft_isdigit(str[index]))
		index++;
	index = index - tmp;
	if (index == 0)
		return (0);
	res = 1;
	while (index-- > 1)
		res = res * 10;
	return (res);
}

int					ft_atoi(const char *str)
{
	int				res;
	int				max_range;
	size_t			index;
	size_t			neg;

	res = 0;
	index = 0;
	while ((str[index] > 8 && str[index] < 14) || (str[index] == ' '))
		index++;
	neg = index;
	if (str[index] == '+' || str[index] == '-')
		index++;
	max_range = get_max_range(str, index);
	while (max_range > 0)
	{
		res = res + (str[index++] - '0') * max_range;
		max_range = max_range / 10;
	}
	if (str[neg] == '-')
		res = res * -1;
	return (res);
}
