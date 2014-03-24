/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:39:37 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:39:37 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell3.h>
#include <stdlib.h>
#include <term.h>

void	sh_quit(void)
{
	sh_reset_termios();
	set_winstruct(NULL, 1);
	tputs(tgetstr("ei", NULL), 0, tputchar);
	_Exit(0);
}

