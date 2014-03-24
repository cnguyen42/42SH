/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_move2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:39:10 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:39:10 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell3.h>
#include <term.h>

void				carriage_ret(void)
{
	tputs(tgetstr("cr", NULL), 1, tputchar);
	tputs(tgetstr("do", NULL), 1, tputchar);
}

void				go_right_to(t_usent *us, int start, int end)
{
	int		i;

	i = start;
	while (i < end)
	{
		go_right(us);
		i++;
	}
}
