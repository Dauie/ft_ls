/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treesearch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:08:42 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/16 15:00:51 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
