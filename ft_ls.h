#ifndef ft_ls_H
# define ft_ls_H

#include "libft/incl/str.h"
#include "libft/incl/printf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct	s_stat
{
	nlink_t		nlink;
	uid_t		uid;
	gid_t		gid;
	off_t		size;
	time_t		atime;
	time_t		mtime;
}				t_stat;

typedef struct		s_node
{
	unsigned int	key;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;


void 		addtnode(t_node	**tree, unsigned int key);
int			treesearch(t_node *tree, unsigned int key);
void 		printtree(t_node *tree);
void 		revprinttree(t_node *tree);
void 		cleartree(t_node *tree);


# endif
