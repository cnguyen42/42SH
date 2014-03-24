/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:39:12 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:39:12 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		error(char *str_error)
{
	ft_putendl_fd(str_error, 2);
	exit(EXIT_FAILURE);
}