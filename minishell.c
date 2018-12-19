/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:02:01 by fdikilu           #+#    #+#             */
/*   Updated: 2018/12/19 19:39:06 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**do_cmd(char **env, t_list *l_cmd)
{
	t_list	*tmp;

	tmp = l_cmd;
	while (l_cmd)
	{
		if (ft_strcmp(((char **)l_cmd->content)[0], "exit") == 0)
			ft_exit(env, tmp);
		env = ft_exec(env, (char **)l_cmd->content);
		l_cmd = l_cmd->next;
	}
	l_cmdfree(tmp);
	return (env);
}

int			main(int ac, char **av, char **env)
{
	char	**shell_env;
	char	*line;
	t_list	*l_cmd;

	(void)av;
	if (!(shell_env = ft_reset_env(env, 0)))
		return (0);
	while (ac)
	{
		ft_putstr("$> ");
		get_next_line(0, &line);
		if (!(l_cmd = ft_lexer_p2(shell_env, line)))
			ft_strdel(&line);
		ft_strdel(&line);
		shell_env = do_cmd(shell_env, l_cmd);
	}
	return (0);
}
