/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:51:50 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/24 15:51:52 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void				set_signal(void)
{
	int				sig[SIG_S] = SIG1;
	int				i;

	i = 0;
	while (i < SIG_S)
	{
		signal(sig[i], signal_handler);
		i++;
	}
}

void				signal_handler(int sign)
{
	int				sig[SIG_S] = SIG1;
	void			(*sig_e[SIG_S])(int) = SIG_E1;
	int				i;

	i = 0;
	while (i < SIG_S)
	{
		if (sign == sig[i])
		{
			sig_e[i](sign);
			break ;
		}
		i++;
	}
}

void				ft_sigint(int sign)
{
	char			*pid_execv;

	pid_execv = ft_getenv("PID_EXECV");
	ft_putchar('\n');
	if (!pid_execv)
		printprompt(NULL);
	else
		kill(ft_atoi(pid_execv), sign);
}

void				ft_sigusr1(int sign)
{
	exit(0);
	(void)sign;
}

void				ft_sigign(int sign)
{
	signal(sign, SIG_IGN);
}
