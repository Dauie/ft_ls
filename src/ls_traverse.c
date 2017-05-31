#include "../incl/ft_ls.h"

void				ls_traverse(t_lnode *tree, t_lsnfo *info)
{
	if (tree)
	{
		if (tree->left)
			ls_traverse(tree->left, info);
		if (tree->type == 'f')
			ls_listfile(info, tree->name);
		else if (tree->type == 'd')
			ls_listdir(info, tree->name);
		if (info->nl)
		{
			ft_putchar('\n');
			info->nl--;
		}
		if (tree->right) 
			ls_traverse(tree->right, info);
	}
}

void				ls_traverserev(t_lnode *tree, t_lsnfo *info)
{
	if (tree)
	{
		if (tree->right)
			ls_traverserev(tree->right, info);
		if (tree->type == 'f')
			ls_listfile(info, tree->name);
		else if (tree->type == 'd')
			ls_listdir(info, tree->name);
		if (info->nl)
		{
			ft_putchar('\n');
			info->nl--;
		}
		if (tree->left)
			ls_traverserev(tree->left, info);
	}
}