/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_p2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:55:01 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/21 18:09:03 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*set_argv(t_list *l_cmd)
{
	t_list	*l_tmp;
	char	**tmp;

	l_tmp = l_cmd;
	while (l_cmd)
	{
		if (!(tmp = ft_strsplit(l_cmd->content, ' ')))
		{
			ft_lstclr(&l_cmd);
			l_cmd = NULL;
			l_cmdfree(l_tmp);
			return (NULL);
		}
		ft_strdel((char **)&(l_cmd->content));
		l_cmd->content = tmp;
		l_cmd = l_cmd->next;
	}
	return (l_tmp);
}

static t_list	*set_path(char **env, t_list *l_cmd)
{
	char	*tmp;
	t_list	*l_tmp;

	if (!(l_cmd = set_argv(l_cmd)))
	{
		l_cmdfree(l_cmd);
		return (NULL);
	}
	l_tmp = l_cmd;
	while (l_cmd)
	{
		if (!((char **)l_cmd->content)[0])
		{
			l_cmdfree(l_tmp);
			return (NULL);
		}
		if (check_builtin(((char **)l_cmd->content)[0])
			&& (tmp = ft_findinpath(env, ((char **)l_cmd->content)[0])))
		{
			ft_strdel(&(l_cmd->content[0]));
			((char **)l_cmd->content)[0] = tmp;
		}
		l_cmd = l_cmd->next;
	}
	return (l_tmp);
}

t_list			*ft_lexer_p2(char **env, char *line)
{
	t_list	*l_cmd;

	if (!line)
		return (NULL);
	if (!(l_cmd = ft_lexer(line)))
		return (NULL);
	if (!(l_cmd = set_path(env, l_cmd)))
		return (NULL);
	dollar_tilde(env, l_cmd);
	return (l_cmd);
}
