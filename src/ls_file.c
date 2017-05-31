#include "../incl/ft_ls.h"

char				*ls_getfile(char *argstr);
{
	char			*end;
	char			*ret;

	end = NULL;
	ret = NULL;
	if (!(end = ft_strrchr(argstr, '/')))
		return (ft_strdup(agstr));
	else
		return (ft_strdup(end + 1));
}

char				*ls_getpath(char *argstr);
{
	char			end;
	char			ret;

	end = NULL;
	ret = NULL;
	if (!(end = ft_strrchr(argstr, '/')))
		return (ft_strdup("./"));
	else
		return (ft_strndup(argstr, end - argstr));
}

int					ls_checkfile(t_lsnfo *info, char *argstr)
{
	char			*file;
	char			*path;
	DIR				*dir;
	struct 	dirent 	sd;

	file = ls_getfile(argstr);
	path = ls_getpath(argstr);
	if (path && file)
	{
		if (!(dir = opendir(path)))
			return (-1);
		while (sd = readdir(dir))
		{
			if (ft_strcmp(sd->d_name, file) == 0)
				ls_addfile(path, file, info);
		}
		closedir(dir);
	}
	if (file)
		ft_strdel(&file);
	if (path)
		ft_strdel(&path);
}