/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_user_entry_get_key.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:40:35 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:40:35 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell3.h>

static t_k_type		sh_key_is_simple(t_usent *us)
{
	static t_simp_key		s_k[] = {
		{10, K_LF},
		{27, K_ESC},
		{12, K_CTRL_L},
		{127, K_DELETE},
		{0, K_NONE},
	};
	int						i;

	i = 0;
	while (s_k[i].k_type != K_NONE)
	{
		if (s_k[i].c == us->buf[0])
			return (s_k[i].k_type);
		i++;
	}
	return (K_NONE);
}

static t_k_type		sh_key_is_sequence(t_usent *us)
{
	static t_simp_key		s_k[] = {
		{65, K_UP},
		{66, K_DOWN},
		{67, K_RIGHT},
		{68, K_LEFT},
		{51, K_SUPPR},
		{70, K_END},
		{72, K_HOME},
		{0, K_NONE},
	};
	int						i;

	i = -1;
	while (s_k[++i].k_type != K_NONE)
	{
		if (s_k[i].c == us->buf[2])
			return (s_k[i].k_type);
	}
	return (K_NONE);
}

t_k_type			sh_key_get(t_usent *us)
{
	if (us->buf[1] == 0 && us->buf[2] == 0)
		return (sh_key_is_simple(us));
	if (us->buf[0] == 27 && us->buf[1] == 91)
		return (sh_key_is_sequence(us));
	return (K_NONE);
}
