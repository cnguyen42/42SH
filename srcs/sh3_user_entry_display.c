/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_user_entry_display.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:39:57 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:39:57 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell3.h>
#include <unistd.h>
#include <term.h>

void			sh_print_from(t_usent *us)
{
	int		i;
	int		line;
	int		col;

	line = us->curs_line;
	col = us->curs_col;
	tputs(tgetstr("cd", NULL), 0, tputchar);
	i = INDEX;
	while (us->edit[i] != '\0')
	{
		set_cursor_position(us, 1);
		write(1, &(us->edit[i]), 1);
		i++;
	}
	while (line != us->curs_line || us->curs_col != col)
		go_left(us);
}

int				read_print_user_entry(t_usent *us)
{
	ft_memset(us->buf, '\0', 5);
	read(STDIN_FILENO, us->buf, 5);
	if (us->buf[0] == 4)
		return (1);
	if (ft_isprint(us->buf[0]) == 1)
	{
		write(1, &(us->buf[0]), 1);
		set_cursor_position(us, 1);
		if (us->insert == TRUE)
			sh_print_from(us);
	}
	return (0);
}
