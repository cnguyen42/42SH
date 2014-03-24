/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokentotree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:48:16 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/24 15:48:16 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void				make_split(t_node *cur, int i, t_ope *ope);
void				split_node(t_node *cur, t_ope *ope);

static t_node		*fill_node(t_node *cur, int i, int len, int left)
{
	char			**ctab;

	len = (left) ? i : len - i;
	i = (left) ? 0 : i + 1;
	ctab = ft_ctabsub(cur->ctab, i, len);
	return (new_node(ctab, cur));
}

void				make_split(t_node *cur, int i, t_ope *ope)
{
	cur->left = fill_node(cur, i, cur->len, 1);
	cur->right = fill_node(cur, i, cur->len, 0);
	cur->ctab = ft_ctabsub(cur->ctab, i, 1);
	cur->flag = set_flag(cur, ope, 0);
	cur->oper = set_oper(cur);
	split_node(cur->left, ope);
	split_node(cur->right, ope);
}

void				split_node(t_node *cur, t_ope *ope)
{
	int				i;
	int				j;
	int				level;

	level = 0;
	while (level <= LEVEL_MAX)
	{
		i = 0;
		while (cur->ctab[i] && cur->flag)
		{
			j = 0;
			while (cur->flag && j < OPE_SIZE)
			{
				if (ope[j].level == level
					&& ft_strequ(ope[j].ope, cur->ctab[i]))
					make_split(cur, i, ope);
				j++;
			}
			i++;
		}
		level++;
	}
}

t_node				*token_to_tree(char **tokens, t_ope *ope)
{
	t_node			*current;

	tokens = check_gnl(tokens);
	current = new_node(tokens, NULL);
	split_node(current, ope);
	check_fd(current);
	check_case(current);
	return (current);
}
