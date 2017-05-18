/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_treesrch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:08:42 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/18 11:51:46 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

int				ls_treesearch(t_node *tree, char *name)
{
	t_node		*tmp;

	tmp = tree;
	while (tmp)
	{
		if (name == tmp->name)
			return (1);
		if (ft_strcmp(name, tmp->name) > 0)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	return (0);
}

unsigned int	ls_diramnt(t_node *tree)
{
	if (!tree)
		return (0);
	if (S_ISDIR(tree->stat.st_mode))
		return (1);
	else
		return ((ls_diramnt(tree->left) + ls_diramnt(tree->right)));
}

unsigned int	ls_getmbramt(t_rnode *tree)
{
	if (!tree)
		return (0);
	if (tree)
		return (1);
	else
		return ((ls_getmbramt(tree->left) + ls_getmbramt(tree->right)));
}

void			ls_dirtree(t_node *tree, t_lsnfo *db, char **av, size_t inx)
{
	if (!tree)
		return ;
	if (tree->left)
		ls_dirtree(tree->left, db, av, inx);
	if (S_ISDIR(tree->stat.st_mode))
	{
		av[inx] = ft_strjoin(db->cdir, tree->name);
		inx++;
	}
	if (tree->right)
		ls_dirtree(tree->right, db, av, inx);
}
