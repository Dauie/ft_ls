#include "../incl/ft_ls.h"

t_lnode			*prep_addnode(char *name, char type)
{
	t_lnode		*elem;

	if (!(elem = (t_lnode *)ft_memalloc(sizeof(t_lnode))))
		return (NULL);
	ls_initnode(elem);
	ft_strcpy(elem->name, name);
	elem->type = type;
	lstat(name, &elem->st);
	return (elem);
}

void			ls_addnodename(t_lnode **tree, char *name, char type)
{
	t_trinode	tri;

	tri.tt = *tree;
	tri.el = prep_addnode(name, type);
	if (tri.tt)
	{
		while (tri.tt)
		{
			tri.nt = tri.tt;
			if (ft_strcmp(tri.el->name, tri.tt->name) < 0)
			{
				tri.tt = tri.tt->left;
				if (!tri.tt)
					tri.nt->left = tri.el;
			}
			else
			{
				tri.tt = tri.tt->right;
				if (!tri.tt)
					tri.nt->right = tri.el;
			}
		}
	}
	else
		*tree = tri.el;
}

void			ls_addnodetime(t_lnode **tree, char *name, char type)
{
	t_trinode	tri;

	tri.tt = *tree;
	tri.el = prep_addnode(name, type);
	if (tri.tt)
	{
		while (tri.tt)
		{
			tri.nt = tri.tt;
			if (ls_compt(&tri.el->st, &tri.tt->st, tri.el->name, tri.tt->name) < 0)
			{
				tri.tt = tri.tt->left;
				if (!tri.tt)
					tri.nt->left = tri.el;
			}
			else
			{
				tri.tt = tri.tt->right;
				if (!tri.tt)
					tri.nt->right = tri.el;
			}
		}
	}
	else
		*tree = tri.el;
}