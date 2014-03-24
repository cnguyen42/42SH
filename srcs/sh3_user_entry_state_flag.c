/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_user_entry_state_flag.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:40:42 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:40:42 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell3.h>

void	sh_entry_prompt_flag(t_usent *us, char key)
{
	int						i;
	const char				*a[] = {
		"``",
		"\"\"",
		"\'\'",
		"{}",
		"()"
	};

	i = 0;
	while (i < 5)
	{
		if (key == a[i][0] && us->pf[i] == '0')
			us->pf[i] = '1';
		else if (key == a[i][1] && us->pf[i] == '1')
			us->pf[i] = '0';
		else if (key != a[i][0] && key != a[i][1] && us->pf[i] == '1')
			break ;
		i++;
	}
	if (us->pf[2] == '1')
	{
		us->pf[0] = '0';
		us->pf[1] = '0';
	}
}

void			sh_entry_linefeed(t_usent *us)
{
	int				i;

	i = 0;
	while (us->edit[i] != '\0')
	{
		sh_entry_prompt_flag(us, us->edit[i]);
		i++;
	}
	sh_prompt(us);
	sh_init_prompt_flag(us);
}
