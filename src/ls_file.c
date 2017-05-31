#include "../incl/ft_ls.h"

char				*ls_getfile(char *argstr)
{
	char			*end;
	char			*ret;

	end = NULL;
	ret = NULL;
	if (!(end = ft_strrchr(argstr, '/')))
		return (ft_strdup(argstr));
	else
		return (ft_strdup(end + 1));
}

char				*ls_getpath(char *argstr)
{
	char			*end;
	char			*ret;

	end = NULL;
	ret = NULL;
	if (!(end = ft_strrchr(argstr, '/')))
		return (ft_strdup("./"));
	else
		return (ft_strndup(argstr, end - argstr));
}