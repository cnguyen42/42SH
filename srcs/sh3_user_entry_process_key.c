/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_user_entry_process_key.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:40:40 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:40:40 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell3.h>
#include <unistd.h>
#include <term.h>

static void			sh_pk_esc(t_usent *us)
{
	if (us->key == K_ESC)
		sh_quit();
}

static void			sh_pk_linefeed(t_usent *us)
{
	us->edit_limit = us->cursor;
	if (us->insert == TRUE)
		go_right_to(us, us->cursor, us->c_size);
	write(1, "\n", 1);
	sh_entry_linefeed(us);
}

static void			sh_pk_delete(t_usent *us)
{
	if (INDEX > us->edit_limit)
	{
		go_left(us);
		INDEX--;
		tputs(tgetstr("dc", NULL), 0, tputchar);
		us->c_size -= 1;
		ft_strcpy(&(us->edit[INDEX]), &(us->edit[INDEX + 1]));
	}
}

static void			sh_pk_arrow_lft_rght(t_usent *us)
{
	if (us->key == K_LEFT && INDEX > us->edit_limit)
	{
		go_left(us);
		INDEX--;
	}
	if (us->key == K_RIGHT && INDEX < us->c_size)
	{
		go_right(us);
		INDEX++;
	}
	if (INDEX < us->c_size)
		us->insert = TRUE;
	else
		us->insert = FALSE;
}

void				sh_process_key_entry(t_usent *us, int i)
{
	static t_key		pk[] = {
		{K_ESC, sh_pk_esc},
		{K_LF, sh_pk_linefeed},
		{K_DELETE, sh_pk_delete},
		{K_SUPPR, sh_pk_suppr},
		{K_HOME, sh_pk_home},
		{K_END, sh_pk_end},
		{K_CTRL_L, sh_pk_ctrl_l},
		{K_LEFT, sh_pk_arrow_lft_rght},
		{K_RIGHT, sh_pk_arrow_lft_rght},
		{K_UP, sh_pk_arrow_up},
		{K_DOWN, sh_pk_arrow_dn}
	};
	void		(*f)(t_usent *us);

	us->key = sh_key_get(us);
	while (++i < 11)
	{
		if (pk[i].k_type == us->key)
		{
			f = pk[i].f;
			f(us);
			return ;
		}
	}
}
