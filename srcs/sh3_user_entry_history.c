/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_user_entry_history.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:40:39 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:40:39 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell3.h>
#include <unistd.h>
#include <stdlib.h>
#include <term.h>

static void		sh_remalloc_edit(t_usent *us, int ratio)
{
	free(us->edit);
	us->edit = NULL;
	if (!(us->edit = (char*)malloc(sizeof(char) * (ratio * 255))))
		sh_error_quit("us->edit malloc fail");
	ft_memset(us->edit, '\0', ratio * 255);
}

static void		re_write(t_usent *us)
{
	int		i;

	tputs(tgetstr("vi", NULL), 0, tputchar);
	while (INDEX < us->c_size)
	{
		go_right(us);
		INDEX++;
	}
	while (us->curs_line != 0 || us->curs_col != us->prompt_size)
	{
		go_left(us);
		INDEX--;
	}
	tputs(tgetstr("cd", NULL), 0, tputchar);
	us->c_size = (int)ft_strlen(us->edit);
	INDEX = us->c_size;
	i = 0;
	while (i < us->c_size)
	{
		write(1, &(us->edit[i]), 1);
		i++;
		set_cursor_position(us, 1);
	}
	tputs(tgetstr("ve", NULL), 0, tputchar);
}

void			sh_pk_arrow_up(t_usent *us)
{
	int		ratio;

	if (us->hist->prev != NULL)
	{
		if (us->hist->next == NULL)
		{
			free(us->tmp);
			us->tmp = NULL;
			us->tmp = ft_strdup(us->edit);
		}
		us->hist = us->hist->prev;
		ratio = ft_strlen(us->hist->entry) / 255 + 1;
		sh_remalloc_edit(us, ratio);
		ft_strcpy(us->edit, us->hist->entry);
		re_write(us);
	}
}

void			sh_pk_arrow_dn(t_usent *us)
{
	int		ratio;

	if (us->hist->next != NULL)
	{
		us->hist = us->hist->next;
		if (us->hist->next == NULL)
		{
			ratio = ft_strlen(us->tmp) / 255 + 1;
			sh_remalloc_edit(us, ratio);
			ft_strcpy(us->edit, us->tmp);
		}
		else
		{
			ratio = ft_strlen(us->hist->entry) / 255 + 1;
			sh_remalloc_edit(us, ratio);
			ft_strcpy(us->edit, us->hist->entry);
		}
		re_write(us);
	}
}

void			sh_add_history(t_hist **hist)
{
	t_hist		*new_hist;

	new_hist = NULL;
	if (!(new_hist = (t_hist*)malloc(sizeof(t_hist))))
		sh_error_quit("hist malloc fail");
	new_hist->prev = NULL;
	new_hist->next = NULL;
	new_hist->entry = NULL;
	new_hist->entry = (char*)malloc(sizeof(char) * 1);
	new_hist->entry[0] = '\0';
	(*hist)->next = new_hist;
	new_hist->prev = *hist;
	*hist = (*hist)->next;
}
