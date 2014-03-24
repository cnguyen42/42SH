/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:50:46 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/24 15:50:46 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char				**check_gnl(char **tokens)
{
	int				flag;
	int				i;
	char			*line;
	char			**split;

	flag = 0;
	i = 0;
	while (!flag && tokens[i + 1])
	{
		if (ft_strequ(tokens[i], "|") && ft_strequ(tokens[i + 1], ";"))
			flag = 1;
		if (flag)
		{
			ft_putstr("pipe > ");
			get_next_line(0, &line);
			split = ft_strsplit(line, " \t");
			tokens = ft_ctabaddtoindex(tokens, split, i + 1, 0);
		}
		i++;
	}
	return (tokens);
}

void				check_fd(t_node *cur)
{
	char			**right;

	if (cur->ctab[0] && (cur->ctab[0][0] == '>' || cur->ctab[0][0] == '<'))
	{
		right = ft_ctabdup(cur->right->ctab);
		if (!cur->left->ctab[0])
		{
			cur->left->ctab = ft_ctabsub(right, 1, ft_ctablen(right));
			cur->right->ctab = ft_ctabsub(right, 0, 1);
		}
	}
	if (cur->left)
		check_fd(cur->left);
	if (cur->right)
		check_fd(cur->right);
}

static char			**chevron_swapleft(t_node *cur, int left_len, int right_len)
{
	char			**left;
	int				i;
	int				j;

	left = (char **)malloc(sizeof(char *) * (left_len + right_len));
	i = 0;
	while (cur->left->ctab[i])
	{
		left[i] = cur->left->ctab[i];
		i++;
	}
	j = 1;
	while (cur->right->ctab[j])
	{
		left[i] = cur->right->ctab[j];
		i++;
		j++;
	}
	left[i] = NULL;
	return (left);
}

static char			**chevron_swapright(t_node *node_right)
{
	char			**right;
	int				i;

	right = (char **)malloc(sizeof(char *) * 2);
	i = 0;
	right[i] = node_right->ctab[0];
	i++;
	right[i] = NULL;
	return (right);
}

void				check_case(t_node *cur)
{
	char			*cat[2] = {"cat", NULL};
	char			*tee[2] = {"tee", NULL};

	if (cur->oper == 2)
	{
		if (!cur->left->len && cur->right->len == 1 && cur->right->flag == 2)
			cur->left->ctab = ft_ctabaddtoindex(cur->left->ctab, cat, 0, 0);
		if (!cur->left->len && cur->right->len == 1 && cur->right->flag == 4)
			cur->left->ctab = ft_ctabaddtoindex(cur->left->ctab, tee, 0, 0);
		if (cur->right->len > 1)
		{
			cur->left->ctab = chevron_swapleft(cur, cur->left->len,
													cur->right->len);
			cur->right->ctab = chevron_swapright(cur->right);
		}
	}
	if (cur->left)
		check_case(cur->left);
	if (cur->right)
		check_case(cur->right);
}
