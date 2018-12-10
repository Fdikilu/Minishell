/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 21:54:24 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/10 05:37:02 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <sys/types.h>
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

void		ft_cd(char **env, char *path)
{
	int		tmp;
	char	buf[1024];

	(void)env;
	if (chdir(path) == -1)
	{
		if ((tmp = permission_test(path)) == 1)
			write(2, "cd: Permission denied\n", 22);
		else if (tmp == 0)
			write(2, "cd: No such file or directory\n", 30);
		else
			write(2, "cd: Not a directory\n", 20);
	}
	env = ft_setenv(env, "PWD", getcwd(buf, 1024));
}// return void ou char** tester dans le main avec tt les fct env
