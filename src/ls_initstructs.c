#include "../incl/ft_ls.h"

void		ls_initlsnfo(t_lsnfo *info)
{
    info->args = NULL;
	ft_bzero(info->argflgs, MXTYPLEN);
	info->argflgs[0] = '-';
	info->p_args = &info->argflgs[1];
	ft_bzero(info->cdir, MXDIRLEN);
    info->files = NULL;
    info->dirs = NULL;
	info->dircnt = 0;
	info->nl = 0;
	info->f_stop = FALSE;
    info->f_long = FALSE;
    info->f_all = FALSE;
    info->f_jhidden = FALSE;
    info->f_rev = FALSE;
    info->f_time = FALSE;
    info->f_recur = FALSE;

}

void	ls_initnode(t_lnode *node)
{
	node->left = NULL;
	node->right = NULL;
}

void		ls_freetree(t_lnode **tree)
{
	t_lnode		*tmp;

	tmp = *tree;
	if (!tmp)
		return ;
	if (tmp->left)
		ls_freetree(&tmp->left);
	if (tmp->right)
		ls_freetree(&tmp->right);
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
}

void		ls_freeinfo(t_lsnfo *info)
{
	if (info->args)
		ft_tbldel(info->args);
	if (info->files)
		ls_freetree(&info->files);
	if (info->dirs)
		ls_freetree(&info->dirs);
}