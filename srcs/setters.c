/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:39:34 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:39:34 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char			**setctab(char *str)
{
	char		**ctab;

	ctab = (char **)malloc(sizeof(char *));
	ctab[0] = ft_strdup(str);
	return (ctab);
}

t_ope			*set_ope_ord(void)
{
	t_ope		*ope_ord;

	ope_ord = (t_ope *)malloc(sizeof(t_ope) * OPE_SIZE);
	ope_ord[0].level = 0;
	ope_ord[0].ope = ";";
	ope_ord[1].level = 1;
	ope_ord[1].ope = "|";
	ope_ord[2].level = 2;
	ope_ord[2].ope = "<";
	ope_ord[3].level = 2;
	ope_ord[3].ope = "<<";
	ope_ord[4].level = 2;
	ope_ord[4].ope = ">";
	ope_ord[5].level = 2;
	ope_ord[5].ope = ">>";
	ope_ord[6].level = 0;
	ope_ord[6].ope = "&&";
	ope_ord[7].level = 0;
	ope_ord[7].ope = "||";
	return (ope_ord);
}

static void		set_flag_chevron(t_node *cur, int i)
{
	cur->left->flag = 1;
	cur->right->flag = i;
}

int				set_flag(t_node *cur, t_ope *ope, int i)
{
	int			flag;

	flag = -1;
	while (i < OPE_SIZE)
	{
		if (ft_strequ(cur->ctab[0], ope[i].ope))
		{
			flag = 0;
			if (i < 2)
			{
				cur->left->flag = 1;
				cur->right->flag = (cur->right->ctab[0]) ? 1 : 6;
			}
			else
				set_flag_chevron(cur, i);
		}
		i++;
	}
	return (flag);
}

int				set_oper(t_node *cur)
{
	if (cur->ctab[0][0] == ';')
		return (0);
	if (cur->ctab[0][0] == '|')
		if (cur->ctab[0][1] == '|')
			return (4);
	if (cur->ctab[0][0] == '<' || cur->ctab[0][0] == '>')
		return (2);
	if (cur->ctab[0][0] == '&')
		return (3);
	if (cur->ctab[0][0] == '|')
		return (1);
	return (-1);
}

