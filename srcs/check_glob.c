/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_glob.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:39:08 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:39:08 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void					check_glob(char **ctab)
{
	int					i;

	i = 1;
	while (ctab[i] && ctab[i][0] == '-')
		i++;
	while (ctab[i])
		i++;
}
