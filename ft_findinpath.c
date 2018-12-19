/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findinpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:38:51 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/17 15:41:13 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "minishell.h"

static char	*findindir(char *path, char *cmd)
{
	int				len;
	char			*to_exec;
	DIR				*fd;
	struct dirent	*s_dir;

	if (!(fd = opendir(path)))
		return (NULL);
	while ((s_dir = readdir(fd)))
		if (ft_strcmp(cmd, s_dir->d_name) == 0)
		{
			len = ft_strlen(path) + ft_strlen(cmd) + 1;
			if (!(to_exec = ft_strnew(len)))
			{
				closedir(fd);
				return (NULL);
			}
			ft_strcpy(to_exec, path);
			to_exec[ft_strlen(path)] = '/';
			ft_strcpy(&to_exec[ft_strlen(path) + 1], cmd);
			closedir(fd);
			return (to_exec);
		}
	closedir(fd);
	return (NULL);
}

char		*ft_findinpath(char **env, char *cmd)
{
	int		i;
	char	*tmp;
	char	**path;
	char	*to_exec;

	tmp = ft_getvalue(env, "PATH");
	if (!(path = ft_strsplit(tmp, ':')))
		return (NULL);
	i = 0;
	while (path[i])
	{
		if ((to_exec = findindir(path[i], cmd)))
		{
			ft_tabfree(path);
			return (to_exec);
		}
		i++;
	}
	ft_tabfree(path);
	return (NULL);
}
