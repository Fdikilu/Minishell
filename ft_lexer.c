/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 21:57:24 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/19 19:25:25 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*create_cmd(char *line, int size_cmd)
{
	char	*cmd;

	if (!(cmd = ft_strnew(size_cmd)))
		return (NULL);
	ft_strncpy(cmd, line, size_cmd);
	return (cmd);
}

static char		*set_cmd(char **line)
{
	int		i;
	char	*cmd;

	i = 0;
	while (**line && (**line == ' ' || **line == '\t'))
		(*line)++;
	while ((*line)[i] && (*line)[i] != ';')
		i++;
	if ((*line)[i] == ';' && i == 0)
	{
		write(2, "Minishell: syntax error\n", 24);
		return (NULL);
	}
	if (!(cmd = create_cmd(*line, i)))
		return (NULL);
	if ((*line)[i] == ';')
		*line += (i + 1);
	else
		*line += i;
	return (cmd);
}

static t_list	*set_lcmd(char *line)
{
	char	*cmd;
	t_list	*new;
	t_list	*l_cmd;

	l_cmd = NULL;
	while (*line)
	{
		if (!(cmd = set_cmd(&line)))
		{
			ft_lstclr(&l_cmd);
			return (NULL);
		}
		if (!(new = ft_lstnew((char *)cmd, sizeof(*cmd) * ft_strlen(cmd) + 1)))
		{
			ft_strdel(&cmd);
			ft_lstclr(&l_cmd);
			return (NULL);
		}
		ft_strdel(&cmd);
		if (!l_cmd)
			l_cmd = new;
		else
			ft_lstaddend(&l_cmd, new);
	}
	return (l_cmd);
}

static int		ft_check_cmd(t_list *l_cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = l_cmd->content;
	while (tmp[i])
	{
		if (tmp[i] == '|' || tmp[i] == '>' || tmp[i] == '<'
			|| tmp[i] == '\'' || tmp[i] == '\"')
		{
			write(2, "Minishell: syntax error\n", 24);
			return (0);
		}
		i++;
	}
	return (1);
}

t_list			*ft_lexer(char *line)
{
	t_list	*l_cmd;
	t_list	*tmp;

	if (!(l_cmd = set_lcmd(line)))
		return (NULL);
	tmp = l_cmd;
	while (tmp)
	{
		if (!(ft_check_cmd(tmp)))
		{
			ft_lstclr(&l_cmd);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (l_cmd);
}
