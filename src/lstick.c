/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstick.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:08:57 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/09 19:42:37 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

int 			ls_tickargs(t_lsnfo *db, char *argstr)
{
	int			i;

	i = -1;
	argstr++;
	while (argstr[++i])
	{
		if (argstr[i] == 'a')
			db->a_flg = TRUE;
		else if (argstr[i] == 'A')
			db->A_flg = TRUE;
		else if (argstr[i] == 'r')
			db->r_flg = TRUE;
		else if (argstr[i] == 'R')
			db->R_flg = TRUE;
		else if (argstr[i] == 'l')
			db->l_flg = TRUE;
		else if (argstr[i] == 't')
			db->t_flg = TRUE;
		else
		{
			ft_printf("ft_ls: illegal option -- %c\n", argstr[i]);
			ft_printf("usage: ft_ls [-lAaRr] [file ...]");
			return (0);
		}
	}
	return (1);
}
