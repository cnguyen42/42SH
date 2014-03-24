/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exectree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:39:13 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:39:13 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				exec_node(t_sh *sh, t_node *cur)
{
	int			tree[TREE_SIZE] = TREE;
	int			(*tree_exec[TREE_SIZE])
				(t_sh *, t_node *, t_node *, t_node *) = TREE_EXEC;
	int			i;

	i = 0;
	while (i < TREE_SIZE)
	{
		if (cur->oper == tree[i])
			return (tree_exec[i](sh, cur, cur->left, cur->right));
		i++;
	}
	return (EXIT_FAILURE);
}

