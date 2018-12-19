/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:32:39 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/18 17:10:54 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	dollar(char **env, t_list *l_cmd)
{
	int		i;
	char	*tmp;
	char	**argv;

	while (l_cmd)
	{
		i = 0;
		argv = (char **)l_cmd->content;
		while (argv[i])
		{
			if (argv[i][0] == '$' && ft_strlen(argv[i]) > 1)
			{
				if ((tmp = ft_strdup(ft_getvalue(env, &(argv[i])[1]))))
				{
					ft_strdel(&(argv[i]));
					argv[i] = tmp;
				}
				else
					ft_strclr(argv[i]);
			}
			i++;
		}
		l_cmd = l_cmd->next;
	}
}

static void	change_tilde(char **env, char **argv)
{
	int		len;
	char	*tmp;
	char	*home;

	if (!(home = ft_getvalue(env, "HOME")))
		return ;
	if (ft_strlen(*argv) == 1)
	{
		if ((tmp = ft_strdup(home)))
		{
			ft_strdel(argv);
			*argv = tmp;
		}
	}
	else if (ft_strlen(*argv) > 1 && (*argv)[1] == '/')
	{
		len = ft_strlen(home) + ft_strlen(*argv) - 1;
		if ((tmp = ft_strnew(len)))
		{
			ft_strcpy(tmp, home);
			ft_strcpy(&tmp[ft_strlen(tmp)], &(*argv)[1]);
			ft_strdel(argv);
			*argv = tmp;
		}
	}
}

static void	tilde(char **env, t_list *l_cmd)
{
	int		i;
	char	**argv;

	while (l_cmd)
	{
		i = 0;
		argv = (char **)l_cmd->content;
		while (argv[i])
		{
			if (argv[i][0] == '~')
				change_tilde(env, &argv[i]);
			i++;
		}
		l_cmd = l_cmd->next;
	}
}

void		dollar_tilde(char **env, t_list *l_cmd)
{
	dollar(env, l_cmd);
	tilde(env, l_cmd);
}
