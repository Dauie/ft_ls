/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtnode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:00:51 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/12 19:07:10 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*42 - Robert Wyatt Lutt - ft_ls*/

#include "ft_ls.h"

static void nodeinit(t_node **tree, t_node *elem, t_node *ttmp, t_node *ntmp)
{
	ttmp = *tree;
	if (!(elem = (t_node *)ft_memalloc(sizeof(t_node))))
		return ;
	elem->right = NULL;
	elem->left = NULL;
}

void 		addtnode(t_node	**tree, unsigned int key)
{
	t_node	*elem;
	t_node	*ttmp;
	t_node	*ntmp;
	
	nodeinit(tree, elem, ttmp, ntmp);
	elem->key = key;
	if (ttmp)
	{
		ntmp = ttmp;
		while (ttmp)
		{
			if (key > ttmp->key)
			{
				ttmp = ttmp->right;
				if (!ttmp)
					ntmp->right = elem;
			}
			else
			{
				ttmp = ttmp->left;
				if (!ttmp)
					ntmp->left = elem;
			}
		}
	}
	else
		tree = &elem;
}
