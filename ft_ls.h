/* Start getting information from lstat tomorrow and make some more useful binary tree funcs */

#ifndef ft_ls_H
# define ft_ls_H

#include "libft/incl/bool.h"
#include "libft/incl/char.h"
#include "libft/incl/cnvrsn.h"
#include "libft/incl/gnl.h"
#include "libft/incl/lst.h"
#include "libft/incl/mem.h"
#include "libft/incl/num.h"
#include "libft/incl/put.h"
#include "libft/incl/printf.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef	enum		s_dftype
{
	LS_NRML,
	LS_FILE,
	LS_EXE,
	LS_LINK,
	LS_DIR,
}					t_dftype;

typedef struct		s_istat
{
	nlink_t			nlink;
	uid_t			uid;
	gid_t			gid;
	off_t			size;
	time_t			atime;
	time_t			mtime;
}					t_istat;

typedef struct		s_node
{
	char 			*name;
	t_dftype		type;
	t_istat			*data;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

typedef struct		s_lsnfo
{
	char			**args;
	t_blean			l_flg;
	t_blean			A_flg;
	t_blean			a_flg;
	t_blean			R_flg;
	t_blean			r_flg;
	t_blean			t_flg;
}					t_lsnfo;

void 				addtnode(t_node	**tree, char *name);
// int					treesearch(t_node *tree, unsigned int key);
void 				printtree(t_node *tree);
void 				revprinttree(t_node *tree);
void 				cleartree(t_node **tree);

# endif
