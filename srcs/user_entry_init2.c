/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_entry_init2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:48:20 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/24 15:48:46 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell3.h>

void			sh_init_prompt_flag(t_usent *us)
{
	us->pf[0] = '0';
	us->pf[1] = '0';
	us->pf[2] = '0';
	us->pf[3] = '0';
	us->pf[4] = '0';
}

void			sh_init_hist(t_hist **hist)
{
	if (*hist == NULL)
	{
		if (!(*hist = (t_hist*)malloc(sizeof(t_hist))))
			sh_error_quit("hist malloc fail");
		(*hist)->prev = NULL;
		(*hist)->next = NULL;
		(*hist)->entry = NULL;
		(*hist)->entry = (char*)malloc(sizeof(char) *2);
		(*hist)->entry[0] = '\0';
	}
}

