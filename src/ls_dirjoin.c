#include "../incl/ft_ls.h"

char			*ls_dirjoin(const char *stra, const char *strb)
{
	char		*ns;

	if (stra == NULL || strb == NULL)
		return (NULL);
	if (!(ns = ft_strnew((ft_strlen(stra) + 1) + ft_strlen(strb))))
		return (NULL);
	ft_strcpy(ns, (char *)stra);
	ft_strcat(ns, "/");
	ft_strcat(ns, strb);
	return (ns);
}
