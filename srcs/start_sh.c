/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:40:53 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:40:53 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <minishell3.h>

static char			*add_end(char *cmd)
{
	int				len;
	char			*new_cmd;

	len = ft_strlen(cmd);
	if (cmd[len - 1] != ';')
	{
		new_cmd = (char *)malloc(sizeof(char) * (len + 2));
		new_cmd = ft_strcpy(new_cmd, cmd);
		new_cmd[len] = ';';
		new_cmd[len + 1] = '\0';
		return (new_cmd);
	}
	return (cmd);
}

void				start_sh(t_sh *sh)
{
	char			*cmd;
	char			*new_tab;
	char			*ope[OPE_SIZE + 1] = OPE;

	if (!(cmd = get_user_entry()))
		*(sh->stop) = 1;
	sh->term.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &(sh->term));
	if (!(*(sh->stop)) && cmd[0])
	{
		new_tab = add_end(cmd);
		sh->tokens = splittoken(sh->tokens, new_tab, ope);
		sh->ope_ord = set_ope_ord();
		sh->root = token_to_tree(sh->tokens, sh->ope_ord);
		if (sh->root->left->ctab[0])
			exec_node(sh, sh->root);
	}
	sh->term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &(sh->term));
	free(cmd);
	dup2(sh->ft_stdin, 0);
	dup2(sh->ft_stdout, 1);
	close(sh->ft_stdin);
	close(sh->ft_stdout);
}
