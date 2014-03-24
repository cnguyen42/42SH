/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:51:30 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/24 15:51:30 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static int			get_state_c(char c)
{
	char			st_c[ST_C_SIZE] = ST_C;
	int				st_c_value[ST_C_SIZE] = ST_C_VALUE;
	int				i;

	i = 0;
	while (i < ST_C_SIZE)
	{
		if (st_c[i] == c)
			return (st_c_value[i]);
		i++;
	}
	return (NO);
}

static void			change_bool(t_cmd *cmd, int user_input, int new_state)
{
	user_input = (user_input == 6) ? 4 : user_input;
	user_input = (user_input == 7) ? 5 : user_input;
	if (new_state == NO)
		cmd->state_bool[user_input - 1]--;
	else
		cmd->state_bool[user_input - 1]++;
}

static int			check_bool(t_cmd *cmd)
{
	int				i;

	i = 0;
	while (i < STRINGS_SIZE)
	{
		if (cmd->state_bool[i])
			return (i + 1);
		i++;
	}
	return (NO);
}

static int			get_state(t_cmd *cmd, int state_c, int i)
{
	static int		automate[][3] =
	{{NO, BQUOTE, BQUOTE}, {NO, QUOTE, QUOTE}, {NO, DQUOTE, DQUOTE},
	{NO, SUBSH_I, SUBSH_I}, {NO, CURSH_I, CURSH_I}, {BQUOTE, BQUOTE, NO},
	{QUOTE, QUOTE, NO}, {DQUOTE, BQUOTE, BQUOTE}, {DQUOTE, DQUOTE, NO},
	{SUBSH_I, BQUOTE, BQUOTE}, {SUBSH_I, QUOTE, QUOTE},
	{SUBSH_I, DQUOTE, DQUOTE}, {SUBSH_I, SUBSH_O, NO},
	{CURSH_I, BQUOTE, BQUOTE}, {CURSH_I, QUOTE, QUOTE},
	{CURSH_I, DQUOTE, DQUOTE}, {CURSH_I, SUBSH_I, SUBSH_I},
	{CURSH_I, CURSH_O, NO}};

	while (i < 18)
	{
		if (automate[i][0] == cmd->state && automate[i][1] == state_c)
		{
			change_bool(cmd, automate[i][1], automate[i][2]);
			if (automate[i][2] == NO)
				return (check_bool(cmd));
			return (automate[i][2]);
		}
		i++;
	}
	return (cmd->state);
}

void				check_state(t_cmd *cmd)
{
	t_dlst_cmd		*current;
	int				i;

	cmd->state = 0;
	i = 0;
	while (i < STRINGS_SIZE)
	{
		cmd->state_bool[i] = 0;
		i++;
	}
	current = *(cmd->adlst);
	i = 0;
	while (i < cmd->size)
	{
		cmd->state = get_state(cmd, get_state_c(current->c), 0);
		current = current->next;
		i++;
	}
}
