/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:40:54 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:40:54 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void					set_terminal(t_sh *sh)
{
	if (tgetent(NULL, ft_getenv("TERM")) < 1)
	{
		ft_putendl_fd("42sh: invalid TERM", 2);
		exit(EXIT_SUCCESS);
	}
	tcgetattr(STDIN_FILENO, &(sh->term));
	sh->term.c_lflag &= ~(ECHO | ICANON);
	sh->term.c_cc[VMIN] = 0;
	sh->term.c_cc[VTIME] = 1;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &(sh->term));
}

