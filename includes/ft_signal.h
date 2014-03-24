/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 14:29:07 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 14:29:07 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNAL_H
# define FT_SIGNAL_H

# include <signal.h>

# define SIG1 	{SIGINT, SIGQUIT, SIGUSR1}
# define SIG_E1 {ft_sigint, ft_sigign, ft_sigusr1}
# define SIG_S	3

void		set_signal(void);
void		signal_handler(int sign);

void		ft_sigexit(int sign);
void		ft_sigint(int sign);
void		ft_sigusr1(int sign);
void		ft_sigign(int sign);

# endif /* !FT_SIGNAL_H */
