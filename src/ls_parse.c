/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 21:54:12 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/26 16:45:30 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

static int			ls_checkcdir(t_lsnfo *db, char *argstr)
{
	DIR				*dot;
	struct dirent	*sd;

	if (!(dot = opendir(".")))
		return (-1);
	while ((sd = readdir(dot)) != NULL)
	{
		if (ft_strcmp(sd->d_name, argstr) == 0)
		{
			if (db->t_flg)
				ls_addrnodet(&db->dirs, argstr);
			else
				ls_addrnoden(&db->dirs, argstr);
			closedir(dot);
			return (1);
		}
	}
	closedir(dot);
	return (0);
}

static int			ls_vrfydir(t_lsnfo *db, char *argstr)
{
	DIR				*chkdir;
	

	if (!(chkdir = opendir(argstr)))
	{
		if (!(ls_checkcdir(db, argstr)))
			ft_printf("ft_ls: %s no such file or directory\n", argstr);
		return (0);
	}
	closedir(chkdir);
	if (db->t_flg)
		ls_addrnodet(&db->dirs, argstr);
	else
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
			db->aa_flg = TRUE;
		else if (argstr[i] == 'r')
			db->r_flg = TRUE;
		else if (argstr[i] == 'R')
			db->rr_flg = TRUE;
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
		if (!(ls_tickargs(db, &db->args[0][1], -1)))
			return (0);
		ft_strcpy(db->type, db->args[0]);
		i = 0;
	}
	while (db->args[++i])
	{
		if (!(ls_vrfydir(db, db->args[i])))
		{
			db->fu_flg = TRUE;
			db->dirc++;
			continue ;
		}
	}
	return (1);
}

int					ls_chkdirnam(t_lsnfo *db, char *dirnam)
{
	if (db->a_flg == TRUE)
		return (0);
	if (db->a_flg == FALSE && db->aa_flg == FALSE && dirnam[0] == '.')
		return (1);
	if (db->aa_flg == TRUE && (ft_strcmp(".", dirnam) == 0))
		return (1);
	if (db->aa_flg == TRUE && (ft_strcmp("..", dirnam) == 0))
		return (1);
	return (0);
}
