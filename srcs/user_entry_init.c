/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_entry_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:48:32 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/24 15:48:32 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell3.h>
#include <stdlib.h>
#include <term.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <sh.h>

void	set_winstruct(struct winsize **win, int destroy)
{
	static struct winsize		**winstruct = NULL;

	if (winstruct == NULL)
	{
		if (!(winstruct = (struct winsize **)malloc(sizeof(struct winsize*))))
			sh_error_quit("malloc winstruct failed.");
		*winstruct = NULL;
	}
	if (win != NULL)
		*winstruct = *win;
	ioctl(0, TIOCGSIZE, *winstruct);
	if (destroy)
	{
		free(winstruct);
		win = NULL;
	}
}

void	handle_winsize(int	sig)
{
	(void)sig;
	set_winstruct(NULL, 0);
}

void			sh_init_usent(t_usent *us, t_hist *hist)
{
	us->key = K_NONE;
	us->leave = FALSE;
	us->edit = NULL;
	us->tmp = NULL;
	us->cursor = 0;
	us->c_size = 0;
	us->insert = FALSE;
	us->curs_col = 0;
	us->curs_line = 0;
	us->prompt_size = 0;
	if (!(us->winsize = (struct winsize *)malloc(sizeof(struct winsize))))
		sh_error_quit("malloc winsize failed.");
	set_winstruct(&(us->winsize), 0);
	us->edit_limit = 0;
	if (us->edit == NULL)
	{
		if (!(us->edit = (char*)malloc(sizeof(char) * 255)))
			sh_error_quit("malloc us->edit fail");
		ft_memset(us->edit, '\0', 255);
		us->tmp = ft_strdup(us->edit);
		if (us->tmp == NULL)
			sh_error_quit("hist to edit cpy fail");
	}
	us->hist = hist;
	sh_init_prompt_flag(us);
}

void	user_entry_init(t_hist **hist, t_usent *us)
{
	sh_set_termios();
	sh_init_hist(hist);
	signal(SIGWINCH, handle_winsize);
	if (hist == NULL)
		sh_error_quit("hist is NULL");
	sh_init_usent(us, *hist);
	printprompt(&us);
}
