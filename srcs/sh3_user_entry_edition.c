/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_user_entry_edition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:39:58 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:40:22 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell3.h>
#include <stdlib.h>
#include <term.h>

static void			sh_make_str_bigger(t_usent *us, int	size)
{
	static int		ref = 255;
	char			*new;

	if (size < 255)
		ref = 255;
	if (size >= ref)
	{
		ref = ref * (us->c_size / 255 + 1);
		new = NULL;
		new = (char*)malloc(sizeof(char) * ref);
		if (!new)
			sh_error_quit("str_bigger new malloc fail");
		ft_memset(new, '\0', ref);
		ft_strcpy(new, us->edit);
		free(us->edit);
		us->edit = new;
	}
}

void			sh_edition(t_usent *us)
{
	int		s;

	us->c_size = (us->c_size == 0 ? (int)ft_strlen(us->edit) : us->c_size);
	if (ft_isprint(us->buf[0]) == 1)
	{
		if (us->insert == TRUE)
		{
			s = ft_strlen(&(us->edit[INDEX]));
			ft_memmove(&(us->edit[INDEX + 1]), &(us->edit[INDEX]), s);
		}
		us->edit[INDEX] = us->buf[0];
		us->edit[us->c_size + 1] = '\0';
		INDEX++;
		us->c_size++;
		if (us->key == K_LF)
			us->edit_limit = INDEX;
	}
	sh_make_str_bigger(us, us->c_size);
}
