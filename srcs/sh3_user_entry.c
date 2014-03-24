/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_user_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:48:04 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/24 15:48:04 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell3.h>
#include <stdlib.h>
#include <term.h>

static void			sh_user_clean(t_usent *us)
{
	free(us->edit);
	us->edit = NULL;
	tputs(tgetstr("ei", NULL), 0, tputchar);
}

static int			str_is_only_space(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ')
			return (0);
	}
	return (1);
}

char				*get_user_entry(void)
{
	t_usent			us;
	static t_hist	*hist = NULL;
	char			*line;

	user_entry_init(&hist, &us);
	while (us.leave == FALSE)
	{
		if (read_print_user_entry(&us))
			return (NULL);
		sh_process_key_entry(&us, -1);
		sh_edition(&us);
	}
	if (us.edit[0] != '\0' && str_is_only_space(us.edit) == 0)
	{
		hist->entry = ft_strdup(us.edit);
		sh_add_history(&hist);
	}
	line = ft_strdup(us.edit);
	sh_user_clean(&us);
	return (line);
}
