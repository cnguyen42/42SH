/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_tputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:40:43 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:40:43 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell3.h>
#include <unistd.h>

int		tputchar(int c)
{
	write(0, &c, 1);
	return (0);
}
