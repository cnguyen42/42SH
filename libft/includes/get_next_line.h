/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:35:42 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:35:42 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <libft.h>

# define BUFF_SIZE 32

/*
**	get_next_line.c
*/

int			get_next_line(const int fd, char **line);
void		free_string(char *str);

#endif /* !GET_NEXT_LINE_H */
