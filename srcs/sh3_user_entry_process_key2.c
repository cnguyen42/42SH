/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_user_entry_process_key2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:48:05 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/24 15:48:05 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell3.h>
#include <term.h>
#include <sh.h>

void		sh_pk_suppr(t_usent *us)
{
	tputs(tgetstr("dc", NULL), 0, tputchar);
	us->c_size -= 1;
	ft_strcpy(&(us->edit[INDEX]), &(us->edit[INDEX + 1]));
}

void		sh_pk_home(t_usent *us)
{
	while (us->curs_line != 0 || us->curs_col != us->prompt_size)
	{
		go_left(us);
		INDEX--;
	}
}

void		sh_pk_end(t_usent *us)
{
	while (INDEX < us->c_size)
	{
		go_right(us);
		INDEX++;
	}
}

void		sh_pk_ctrl_l(t_usent *us)
{
	while (INDEX < us->c_size)
	{
		go_right(us);
		INDEX++;
	}
	while (us->curs_line != 0 || us->curs_col != us->prompt_size)
	{
		go_left(us);
		tputs(tgetstr("dc", NULL), 0, tputchar);
		INDEX--;
	}
	free(us->edit);
	if (!(us->edit = (char*)malloc(sizeof(char) * 255)))
		sh_error_quit("malloc us->edit fail");
	ft_memset(us->edit, '\0', 255);
	tputs(tgetstr("cl", NULL), 0, tputchar);
	printprompt(NULL);
}
