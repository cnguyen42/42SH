/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_cmd_tostr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:51:42 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/24 15:51:42 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int					get_len(t_cmd *cmd)
{
	int				len;
	t_dlst_cmd		*current;
	int				i;

	len = cmd->size;
	current = *(cmd->adlst);
	i = 0;
	while (i < cmd->size)
	{
		if (current->c == '\n')
			len++;
		current = current->next;
		i++;
	}
	return (len);
}

char				*ft_dlst_cmd_tostr(t_cmd *cmd)
{
	char			*str;
	t_dlst_cmd		*current;
	int				i;

	str = (char *)malloc(sizeof(char) * (cmd->size + 1));
	current = *(cmd->adlst);
	i = 0;
	while (i < cmd->size)
	{
		str[i] = current->c;
		i++;
		current = current->next;
	}
	str[i] = 0;
	return (str);
}
