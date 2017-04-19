/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtnode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:00:51 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/18 20:38:34 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*42 - Robert Wyatt Lutt - ft_ls*/

#include "../incl/ft_ls.h"

int		ls_getmeta(t_node *elem, char *name)
{
	int			chk;
	struct stat hold;

	chk = 0;
	chk = lstat(name, &hold);
	if (!chk)
		return (-1);
	elem->data.uid = hold.st_uid;
	elem->data.gid = hold.st_gid;
	elem->data.size = hold.st_size;
	elem->data.atime = (long)hold.st_atime;
	elem->data.mtime = (long)hold.st_mtimespec.tv_sec;
	elem->data.mntime = (long)hold.st_mtimespec.tv_nsec;
	return (1);
}

static t_node *prep_addnode (char *name, char type, t_lsnfo *db)
{
	t_node *elem;

	if (!(elem = (t_node *)ft_memalloc(sizeof(t_node))))
		return (NULL);
	ls_initnode(elem);
	elem->name = ft_strdup(name);
	if (db->t_flg == TRUE)
			if (!(ls_getmeta(elem, name)))
				return (NULL);
	elem->type = type;
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
			if (tri.ttmp && tri.elem->data.mtime < tri.ttmp->data.mtime)
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
