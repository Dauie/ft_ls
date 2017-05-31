#include "../incl/ft_ls.h"

static void		ls_printtree(t_lnode *tree, t_lsnfo *info)
{
	if (!tree)
		return ;
	if (tree->left)
		ls_printtree(tree->left, info);
	if (info->f_long == TRUE)
		ls_putnodelong(tree, info);
	else
		ft_printf("%s  ", tree->name);
	ft_printf("%s\t", tree->name);
	if (tree->right)
		ls_printtree(tree->right, info);
}

static void		ls_revprinttree(t_lnode *tree, t_lsnfo *info)
{
	if (!tree)
		return ;
	if (tree->right)
		ls_revprinttree(tree->right, info);
	if (info->f_long == TRUE)
		ls_putnodelong(tree, info);
	else
		ft_printf("%s  ", tree->name);
	if (tree->left)
		ls_revprinttree(tree->left, info);
}

void			ls_manageput(t_lnode *tree, t_lsnfo *info)
{
	size_t	sz;

	sz = 0;
	if ((info->f_recur == TRUE))
		ft_printf("\n%s:\n", tree->fpath);
	if (info->f_long == TRUE)
	{
			ls_getblksz(&sz, tree, info);
			ft_printf("total %lld\n", sz);
	}
	if (info->f_rev == TRUE)
		ls_revprinttree(tree, info);
	else
		ls_printtree(tree, info);
}