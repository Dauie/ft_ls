/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 15:10:27 by rlutt             #+#    #+#             */
/*   Updated: 2017/06/17 16:16:10 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

int					ls_checkfile(t_lsnfo *info, char *argstr)
{
	char			*file;
	char			*path;
	DIR				*dir;
	struct dirent	*sd;

	file = ls_getfile(argstr);
	path = ls_getpath(argstr);
	if (!(dir = opendir(path)))
		return (-1);
	while ((sd = readdir(dir)))
	{
		if (ft_strcmp(sd->d_name, file) == 0)
		{
			ft_strdel(&file);
			ft_strdel(&path);
			ls_addfile(info, argstr);
			return (1);
		}
	}
	closedir(dir);
	ft_strdel(&file);
	ft_strdel(&path);
	return (-1);
}

int					ls_sort(char *argstr, t_lsnfo *info)
{
	DIR				*chkdir;

	if ((chkdir = opendir(argstr)))
	{
		ls_adddir(info, argstr);
		closedir(chkdir);
	}
	else
	{
		if ((ls_checkfile(info, argstr)) == -1)
		{
			ft_printf("ft_ls: %s: No such file or directory\n", argstr);
			return (-1);
		}
	}
	return (1);
}

static int			ls_getflags(t_lsnfo *info, char *argstr, int i)
{
	while (argstr[++i])
	{
		*info->p_args = argstr[i];
		info->p_args++;
		if (argstr[i] == 'a')
			info->f_all = TRUE;
		else if (argstr[i] == 'A')
			info->f_jhidden = TRUE;
		else if (argstr[i] == 'r')
			info->f_rev = TRUE;
		else if (argstr[i] == 'R')
			info->f_recur = TRUE;
		else if (argstr[i] == 'l')
			info->f_long = TRUE;
		else if (argstr[i] == 't')
			info->f_time = TRUE;
		else
		{
			argstr[i + 1] = '\0';
			return (ls_error(-3, &argstr[i]));
		}
	}
	return (1);
}

int					ls_parse(t_lsnfo *info)
{
	int				i;

	i = -1;
	while (info->args[++i] && info->args[i][0] == '-')
	{
		if (!(ls_getflags(info, &info->args[i][1], -1)))
			return (-1);
	}
	while (info->args[i])
	{
		if ((ls_sort(info->args[i++], info)) == -1)
			info->f_stop = TRUE;
	}
	return (1);
}
