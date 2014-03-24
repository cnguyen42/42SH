/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:39:31 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:39:31 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_node				*new_node(char **content, t_node *dad)
{
	t_node			*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->bin = 0;
	node->flag = -1;
	node->oper = -1;
	node->ctab = ft_ctabdup(content);
	node->len = ft_ctablen(content);
	node->dad = dad;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

