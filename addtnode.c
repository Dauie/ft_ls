/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtnode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:00:51 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/13 19:48:35 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*42 - Robert Wyatt Lutt - ft_ls*/

#include "ft_ls.h"

void 		addtnode(t_node	**tree, char *name)
{
	t_node	*elem;
	t_node	*ntmp;
	t_node	*ttmp;

	ttmp = *tree;
	if (!(elem = (t_node *)ft_memalloc(sizeof(t_node))))
		return ;
	elem->right = NULL;
	elem->left = NULL;
	elem->name = ft_strdup(name);
	if (ttmp)
	{
		while (ttmp)
		{
			ntmp = ttmp;
			if (ttmp && ft_strcmp(name, ttmp->name) < 0)
			{
				ttmp = ttmp->left;
				if (!ttmp)
					ntmp->left = elem;
			}
			else
			{
				ttmp = ttmp->right;
				if (!ttmp)
					ntmp->right = elem;
			}
		}
	}
	else
		*tree = elem;
}
