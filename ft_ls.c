/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:46:56 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/14 21:36:54 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*void 	manage_lsattrib(t_node *tree)
{
	if (tree->a_flg == TRUE && tree->A_flg == TRUE)
		tree->A_flg = FALSE;
}*/

int			ft_lsreg(void)
{

	t_node			*tree;
	struct dirent	*sd;
	DIR				*ddir;

	if (!(ddir = opendir(".")))
		return (ft_puterror(-4));
	tree = NULL;
	while ((sd = readdir(ddir)) != NULL)
		addtnode(&tree, sd->d_name);
	printtree(tree);
	closedir(ddir);
	return (0);
}

int				main(int ac, char **av)
{
	t_lsnfo		db;

	if (ac > 1)
	{
		db.args = ft_tbldup(av, ac);
		ft_puttbl(&db.args[1]);
	}
	else
		ft_lsreg();
	return (1);
}
