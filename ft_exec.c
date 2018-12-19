/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:09:36 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/19 23:00:37 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "minishell.h"

static int	runnable(char *cmd)
{
	struct stat	s_st;

	if (lstat(cmd, &s_st) == -1)
	{
		write(2, "Minishell: No such file or directory\n", 37);
		return (0);
	}
	else
	{
		if (S_ISDIR(s_st.st_mode))
		{
			write(2, "Minishell: Is a directory\n", 26);
			return (0);
		}
		if (!(s_st.st_mode & S_IXUSR))
		{
			write(2, "Minishell: Permission denied\n", 29);
			return (0);
		}
		return (1);
	}
}

static void	exec_path(char **env, char **argv)
{
	int		stat_loc;
	pid_t	retfork;

	if (!runnable(argv[0]))
		return ;
	if ((retfork = fork()) == -1)
		return ;
	if (retfork > 0)
		wait(&stat_loc);
	else if (retfork == 0)
		if (execve(argv[0], argv, env) == -1)
			exit(0);
}

static char	**exec_builtin(char **env, char **argv)
{
	if (ft_strcmp(argv[0], "cd") == 0)
		env = ft_cd(env, argv);
	else if (ft_strcmp(argv[0], "pwd") == 0)
		ft_pwd(env);
	else if (ft_strcmp(argv[0], "env") == 0)
		ft_env(env);
	else if (ft_strcmp(argv[0], "setenv") == 0)
		env = ft_setenv(env, argv[1], argv[2]);
	else if (ft_strcmp(argv[0], "unsetenv") == 0)
		env = ft_unsetenv(env, argv[1]);
	else if (ft_strcmp(argv[0], "echo") == 0)
		ft_echo(env, argv);
	return (env);
}

char		**ft_exec(char **env, char **argv)
{
	int		i;

	i = 0;
	while (argv[0][i])
	{
		if (argv[0][i] == '/')
		{
			exec_path(env, argv);
			return (env);
		}
		i++;
	}
	if (!check_builtin(argv[0]))
	{
		env = exec_builtin(env, argv);
		return (env);
	}
	else
	{
		write(2, "Minishell: Command not found\n", 29);
		return (env);
	}
}
