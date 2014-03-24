/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:47:58 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/24 15:47:58 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell3.h>
#include <unistd.h>

void	sh_prompt(t_usent *us)
{
	const char		*prompt[] = {
		"bquote>", "dquote>", "quote>", "cursh>", "subsh>"};
	int				count;
	int				i;
	int				size;

	count = 0;
	i = 0;
	us->prompt_size = 0;
	while (i < 5)
	{
		if (us->pf[i] == '1')
		{
			size  = ft_strlen(prompt[i]);
			write(1, prompt[i], size);
			us->prompt_size += size;
			count++;
		}
		i++;
	}
	us->curs_line = 0;
	us->curs_col = us->prompt_size;
	if (count == 0)
		us->leave = TRUE;
}

void	print_main_prompt(t_usent *us)
{
	(void)us;
	GREEN;
	write(1, "dcojan>", 7);
	DEFCOLOR;
	us->prompt_size = 7;
	us->curs_col = us->prompt_size;
}
