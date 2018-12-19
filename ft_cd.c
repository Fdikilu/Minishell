/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 21:54:24 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/19 23:00:58 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>
#include "minishell.h"

static int	permission_test(char *path)
{
	struct stat	s_st;

	if (lstat(path, &s_st) == -1)
		return (0);
	else
	{
		if (S_ISDIR(s_st.st_mode))
			return (1);
	}
	return (-1);
}

static char	*tmp_path(char **env, char *path)
{
	if (!path)
		return (ft_getvalue(env, "HOME"));
	else if (ft_strcmp(path, "-") == 0)
		return (ft_getvalue(env, "OLDPWD"));
	else
		return (path);
}

char		**ft_cd(char **env, char **argv)
{
	int		perm;
	char	*tmp;
	char	*oldpwd;
	char	buf[1024];

	if (!(tmp = tmp_path(env, argv[1])))
		return (env);
	oldpwd = getcwd(buf, 1024);
	if (chdir(tmp) == -1)
	{
		if ((perm = permission_test(tmp)) == 1)
			write(2, "cd: Permission denied\n", 22);
		else if (perm == 0)
			write(2, "cd: No such file or directory\n", 30);
		else
			write(2, "cd: Not a directory\n", 20);
		return (env);
	}
	env = ft_setenv(env, "OLDPWD", oldpwd);
	return (ft_setenv(env, "PWD", getcwd(buf, 1024)));
}
