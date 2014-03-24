/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:39:10 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:39:10 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell3.h>
#include <term.h>

void				set_cursor_position(t_usent *us, int direction)
{
	us->curs_col = us->curs_col + direction;
	if (us->curs_col < 0 && us->curs_line > 0)
		go_back_up_right(us);
	else if (us->curs_col < 0 && us->curs_line == 0)
		us->curs_line = 0;
	if (us->curs_col == us->winsize->ws_col)
	{
		us->curs_col = 0;
		us->curs_line += 1;
		carriage_ret();
	}
}

void				go_left(t_usent *us)
{
	tputs(tgetstr("le", NULL), 1, tputchar);
	set_cursor_position(us, -1);
}

void				go_right(t_usent *us)
{
	tputs(tgetstr("nd", NULL), 1, tputchar);
	set_cursor_position(us, 1);
}

void				go_back_up_right(t_usent *us)
{
	tputs(tgetstr("up", NULL), 1, tputchar);
	us->curs_line -= 1;
	while (us->curs_col < us->winsize->ws_col - 1)
		go_right(us);
}

