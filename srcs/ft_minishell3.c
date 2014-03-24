/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:47:53 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/24 15:47:53 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell3.h>
#include <unistd.h>
#include <stdlib.h>
#include <term.h>
#include <sh.h>

void	check_terminal(void)
{
	char				*tty_name;
	char				*env_term;
	char				*buff;

	buff = NULL;
	tty_name = NULL;
	env_term = NULL;
	if (isatty(0))
	{
		if (!(tty_name = ttyname(0)))
			sh_error_quit("Error : device not found.");
	}
	else
		sh_error_quit("Error : file descriptor not related with a ter"\
								"minal type device");
	if ((env_term = ft_getenv("TERM")) == NULL)
		sh_error_quit("Error : TERM not found in environment list");
	if (tgetent(buff, env_term) <= 0)
			sh_error_quit("Error : term type database not accessible or" \
			" not defined.");
}
