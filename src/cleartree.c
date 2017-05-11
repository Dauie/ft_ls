/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleartree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:07:26 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/09 18:47:52 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void ls_cleartree(t_node **tree)
{
	t_node		*tmp;

	tmp = *tree;
	if (!tree)
		return ;
	if (tmp->left)
		ls_cleartree(&tmp->left);
	if (tmp->right)
		ls_cleartree(&tmp->right);
	free(tmp);
	tree = NULL;
}

void ls_clearrtree(t_rnode **tree)
{
	t_rnode		*tmp;

	tmp = *tree;
	if (!tree)
		return ;
	if (tmp->left)
		ls_clearrtree(&tmp->left);
	if (tmp->right)
		ls_clearrtree(&tmp->right);
	free(tmp);
	tree = NULL;
}


