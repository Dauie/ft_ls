/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treesearch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:08:42 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/05 16:58:30 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

int		ls_treesearch(t_node *tree, char *name)
{
	t_node	*tmp;

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

void		ls_dirtotbl(t_node *tree, t_lsnfo *db, char **av, size_t inx)
{

	if (!tree)
		return ;
	if (tree->left)
		ls_dirtotbl(tree->left, db, av, inx);
	if (S_ISDIR(tree->stat.st_mode))
	{
		av[inx] = ft_strjoin(db->cdir, tree->name);
		inx++;
	}
	if (tree->right)
		ls_dirtotbl(tree->right, db, av, inx);
}
