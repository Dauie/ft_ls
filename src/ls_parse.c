/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 21:54:12 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/23 17:24:46 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

static int			ls_vrfydir(t_lsnfo *db, char *argstr)
{
	DIR				*chkdir;

	if (!(chkdir = opendir(argstr)))
	{
		ft_printf("ft_ls: %s: No such file or directory\n", argstr);
		return (0);
	}
	closedir(chkdir);
	ls_addrnoden(&db->dirs, argstr);
	db->dirc++;
	return (1);
}

static int			ls_tickargs(t_lsnfo *db, char *argstr, int i)
{
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
			ft_printf("usage: ft_ls [-lAaRr] [file ...]\n");
			return (0);
		}

	}
	return (1);
}

int					ls_anaargs(t_lsnfo *db)
{
	int				i;
	
	i = -1;
	if (db->args[0][0] == '-')
	{
		i++;
		if (!(ls_tickargs(db, &db->args[0][1], -1)))
			return (0);
		ft_strcpy(db->type, db->args[0]);
	}
	while (db->args[++i])
	{
		if (!(ls_vrfydir(db, db->args[i])))
		{
			db->fu_flg = TRUE;
				continue ;
		}
	}
	return (1);
}

int					ls_chkdirnam(t_lsnfo *db, char *dirnam)
{
	if (db->a_flg == TRUE)
		return (0);
	if (db->a_flg == FALSE && db->A_flg == FALSE && dirnam[0] == '.')
		return (1);
	if (db->A_flg == TRUE && (ft_strcmp(".", dirnam) == 0))
		return (1);
	if (db->A_flg == TRUE && (ft_strcmp("..", dirnam) == 0))
		return (1);
	return (0);
}
