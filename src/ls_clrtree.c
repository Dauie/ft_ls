/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_clrtree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:07:26 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/15 22:12:41 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void			ls_clrtree(t_node **tree)
{
	t_node		*tmp;

	tmp = *tree;
	if (!tmp)
		return ;
	if (tmp->left)
		ls_clrtree(&tmp->left);
	if (tmp->right)
		ls_clrtree(&tmp->right);
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
}

void			ls_clrrtree(t_rnode **tree)
{
	t_rnode		*tmp;

	tmp = *tree;
	if (!tmp)
		return ;
	if (tmp->left)
		ls_clrrtree(&tmp->left);
	if (tmp->right)
		ls_clrrtree(&tmp->right);
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
}
