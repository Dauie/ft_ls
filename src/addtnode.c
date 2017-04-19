/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtnode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:00:51 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/18 13:39:45 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*42 - Robert Wyatt Lutt - ft_ls*/

#include "../incl/ft_ls.h"

static time_t	gettime(char *name)
{
	struct stat	fstat;
	
	lstat(name, &fstat);
	return (fstat.st_mtime);
}

static t_node *prep_addnode (char *name, char type, t_lsnfo *db)
{
	t_node *elem;

	if (!(elem = (t_node *)ft_memalloc(sizeof(t_node))))
		return (NULL);
	elem->right = NULL;
	elem->left = NULL;
	elem->name = ft_strdup(name);
	elem->type = type;
	if (db->t_flg == TRUE)
			elem->data->mtime = gettime(name);
	return (elem);
}

void 		ls_addtnoden(t_node **tree, char *name, char type, t_lsnfo *db)
{
	t_trinode	tri;

	tri.ttmp = *tree;
	tri.elem = prep_addnode(name, type, db);
	if (tri.ttmp)
	{
		while (tri.ttmp)
		{
			tri.ntmp = tri.ttmp;
			if (tri.ttmp && ft_strcmp(name, tri.ttmp->name) < 0)
			{
				tri.ttmp = tri.ttmp->left;
				if (!tri.ttmp)
					tri.ntmp->left = tri.elem;
			}
			else
			{
				tri.ttmp = tri.ttmp->right;
				if (!tri.ttmp)
					tri.ntmp->right = tri.elem;
			}
		}
	}
	else
		*tree = tri.elem;
}

void 		ls_addtnodet(t_node **tree, char *name, char type, t_lsnfo *db)
{
	t_trinode	tri;

	tri.ttmp = *tree;
	tri.elem = prep_addnode(name, type, db);
	if (tri.ttmp)
	{
		while (tri.ttmp)
		{
			tri.ntmp = tri.ttmp;
			if (tri.ttmp && tri.elem->data->mtime < tri.ttmp->data->mtime)
			{
				tri.ttmp = tri.ttmp->left;
				if (!tri.ttmp)
					tri.ntmp->left = tri.elem;
			}
			else
			{
				tri.ttmp = tri.ttmp->right;
				if (!tri.ttmp)
					tri.ntmp->right = tri.elem;
			}
		}
	}
	else
		*tree = tri.elem;
}
