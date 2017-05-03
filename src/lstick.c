/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstick.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:08:57 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/03 14:18:39 by rlutt            ###   ########.fr       */
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
		if (ls_isarg(argstr[i]) == 1)
			db->a_flg = TRUE;
		else if (ls_isarg(argstr[i]) == 2)
			db->A_flg = TRUE;
		else if (ls_isarg(argstr[i]) == 3)
			db->r_flg = TRUE;
		else if (ls_isarg(argstr[i]) == 4)
			db->R_flg = TRUE;
		else if (ls_isarg(argstr[i]) == 5)
			db->l_flg = TRUE;
		else if (ls_isarg(argstr[i]) == 6)
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
