/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:39:28 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:39:28 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void				ft_sleep(int i)
{
	int				j;

	j = 0;
	while (j < i * 100000)
		j++;
}
